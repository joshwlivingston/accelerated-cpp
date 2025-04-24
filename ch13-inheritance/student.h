#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <istream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

#include "algorithms.h"

class StudentBase
{
public:
    typedef double grade_type;
    typedef std::vector<grade_type> grades_type;
    friend class Student;
    StudentBase() : midterm(0), final(0) {}
    StudentBase(std::istream &in) { read(in); }
    std::string name() const;
    virtual std::istream &read(std::istream &);
    virtual grade_type grade() const;

protected:
    std::istream &read_common(std::istream &);
    virtual StudentBase *clone() const { return new StudentBase(*this); }
    grade_type midterm;
    grade_type final;
    grades_type homework;

private:
    std::string name_;
};

class StudentGrad : public StudentBase
{
public:
    StudentGrad() : thesis(0) {}
    StudentGrad(std::istream &in) { read(in); }
    grade_type grade() const;
    std::istream &read(std::istream &);

private:
    virtual StudentGrad *clone() const { return new StudentGrad(*this); }
    grade_type thesis;
};

class Student
{
public:
    Student() : student(0) {}
    Student(std::istream &in) : student(0) { read(in); }
    Student(const Student &);
    Student &operator=(const Student &);

    ~Student() { delete student; }

    std::istream &read(std::istream &);
    std::string name() const
    {
        if (!student)
            throw std::runtime_error("Uninitialized student");
        return student->name();
    }
    StudentBase::grade_type grade() const
    {
        if (!student)
            throw std::runtime_error("Uninitialized student");
        return student->grade();
    }
    static bool compare(const Student &student_x, const Student &student_y)
    {
        return student_x.name() < student_y.name();
    }

private:
    StudentBase *student;
};

std::istream read(std::istream &, StudentBase::grades_type &);

StudentBase::grade_type grade(
    const StudentBase::grade_type, const StudentBase::grade_type,
    StudentBase::grades_type::const_iterator,
    StudentBase::grades_type::const_iterator);

StudentBase::grade_type grade(const StudentBase::grade_type,
                              const StudentBase::grade_type,
                              const StudentBase::grade_type);

#endif
