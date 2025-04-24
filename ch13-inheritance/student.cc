#include "student.h"

/* Copy a Student into a new Student object */
Student::Student(const Student &in) : student(0)
{
    if (in.student) student = in.student->clone();
}

Student &Student::operator=(const Student &rhs)
{
    if (&rhs != this)
    {
        delete student;
        if (rhs.student)
            student = rhs.student->clone();
        else
            student = 0;
    }
}

std::istream &Student::read(std::istream &in)
{
    delete student;
    char ch;
    in >> ch;
    if (ch == 'U')
    {
        student = new StudentBase(in);
    }
    else if (ch == 'G')
    {
        student = new StudentGrad(in);
    }
}

/* Returns a student's name */
std::string StudentBase::name() const { return name_; }

/* Calculates and returns the student's final grade */
StudentBase::grade_type StudentBase::grade() const
{
    return ::grade(midterm, final, homework.begin(), homework.end());
}

/* Reads a student's name, midterm exam, final exam, and homework grades 
   from an input stream. */
std::istream &StudentBase::read(std::istream &in)
{
    read_common(in);
    ::read(in, homework);
    return in;
}

/* Reads an input stream, consisting of three parts, read in order:
     1. Student's name
     2. Midterm exam grade
     3. Final exam grade */
std::istream &StudentBase::read_common(std::istream &in)
{
    in >> name_ >> midterm >> final;
    return in;
}

/* Reads a stream of grades into a container of grades */
std::istream read(std::istream &in, StudentBase::grades_type &homework)
{
    StudentBase::grade_type homework_input;
    std::back_insert_iterator<StudentBase::grades_type> 
        homework_inserter = std::back_inserter(homework);
    while (in >> homework_input)
    {
        *homework_inserter = homework_input;
        ++homework_inserter;
    }
}

/* Reads a graduate student's name, midterm exam, final exam, thesis, and
   homework grades from an input stream. */
std::istream &StudentGrad::read(std::istream &in)
{
    read_common(in);
    in >> thesis;
    ::read(in, homework);
    return in;
}

StudentBase::grade_type StudentGrad::grade() const
{
    return algo::min<grade_type>(StudentBase::grade(), thesis);
}

/* Calculates the final grade, provided a midterm grade, final exam grade, and
   a vector of homework grades */
StudentBase::grade_type grade(
    const StudentBase::grade_type midterm,
    const StudentBase::grade_type final,
    StudentBase::grades_type::const_iterator hw_begin,
    StudentBase::grades_type::const_iterator hw_end)
{
    if ((hw_end - hw_begin) == 0)
        throw std::domain_error("Student has done no homework");
    return grade(midterm, final, 
        algo::mean<StudentBase::grades_type::const_iterator, 
        StudentBase::grade_type>(hw_begin, hw_end));
}

/* Applies the correct weighting to the midterm grade, final exam grade, and
   overall homework grade to calculate final grade. */
StudentBase::grade_type grade(const StudentBase::grade_type midterm,
                              const StudentBase::grade_type final,
                              const StudentBase::grade_type homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}