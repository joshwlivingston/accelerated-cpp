#include "student_info.h"

/* Initializes an empty Student object */
Student::Student() : midterm(0), final(0) {}

/* Initializes a Student object using the input stream */
Student::Student(std::istream &in) { read(in); }

/* Reads inccoming data into a Student object. First entry: student's name. If
   'pass' or 'exit' is supplied, a std::runtime_error will be thrown. Second
   entry: the midterm exam grade. Third entry: the final exam grade. Remaining
   entries: the student's homework grades. The next non-numeric entry is taken
   to be the next student's name. */
std::istream &Student::read(std::istream &in)
{
    if (in)
    {
        std::string name_input;
        in >> name_input;
        if (name_input == "pass" || name_input == "exit")
            throw std::runtime_error("program exit");
        name_ = name_input;
        in >> midterm >> final;
        homework.clear();
        grade_num homework_input;
        grade_nums_inserter homework_inserter = std::back_inserter(homework);
        while (in >> homework_input)
            *homework_inserter++ = homework_input;
        in.clear();
    }
    return in;
}

/* Calculates and returns the student's final grade */
Student::grade_num Student::grade() const
{
    return ::grade(midterm, final, homework.begin(), homework.end());
}

/* Calculates the final grade, provided a midterm grade, final exam grade, and
   a vector of homework grades */
Student::grade_num grade(
    const Student::grade_num midterm,
    const Student::grade_num final,
    Student::grade_nums::const_iterator hw_begin,
    Student::grade_nums::const_iterator hw_end)
{
    if ((hw_end - hw_begin) == 0)
        throw std::domain_error("Student has done no homework");
    return grade(
        midterm,
        final,
        algo::mean<Student::grade_nums::const_iterator, Student::grade_num>(
            hw_begin, hw_end));
}

/* Applies the correct weighting to the midterm grade, final exam grade, and
   overall homework grade to calculate final grade. */
Student::grade_num grade(
    const Student::grade_num midterm,
    const Student::grade_num final,
    const Student::grade_num homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

/* Used as predicate to sort() for alphabetical sorting by students' names */
bool compare_name(const Student &student_x, const Student &student_y)
{
    return student_x.name() < student_y.name();
}
