#include <algorithm>
#include <iomanip>
#include <iostream>

#include "student.h"

int main()
{
    std::vector<Student> students;
    Student student;
    std::string::size_type maxlen = 0;
    while (student.read(std::cin))
    {
        maxlen = std::max(maxlen, student.name().size());
        students.push_back(student);
    }

    std::sort(students.begin(), students.end(), Student::compare);

    for (std::vector<Student>::size_type i = 0; i != students.size(); ++i)
    {
        std::cout << students[i].name().size() 
                  << std::string(maxlen + 1 - students[i].name().size(), ' ');
        double final_grade = students[i].grade();
        std::streamsize prec = std::cout.precision();
        std::cout << std::setprecision(3) 
                  << final_grade 
                  << std::setprecision(prec)
                  << std::endl;
    }

    return 0;
}
