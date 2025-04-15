#include <iostream>

#include "student_info.h"
#include "vec.h"

int main()
{
    Student student_input;
    Vec<Student> students;
    try
    {
        while (student_input.read(std::cin))
            students.push_back(student_input);
    }
    catch (std::runtime_error &e)
    {
        std::cout << std::endl;
    }

    Vec<Student>::iterator student = students.begin();
    while (student != students.end())
        std::cout << student++->grade() << std::endl;
    return 0;
}
