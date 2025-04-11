#include <iostream>

#include "student_info.h"

int main()
{
    static const std::vector<Student>::size_type kNumberofStudents = 3;
    std::vector<Student>::size_type i = 0;
    if (i >= kNumberofStudents)
    {
        std::cout << "Invalid program. Cannot read data for a student that "
                     "would exceed the maximum number of students.";
        return 1;
    }

    std::vector<Student> students(kNumberofStudents);
    while (students[i].read(std::cin))
    {
        std::cout << std::endl
                  << std::endl
                  << "Grade (" << students[i].name() << "): "
                  << students[i].grade() << std::endl
                  << std::endl;
        if (++i == kNumberofStudents)
        {
            std::cout << "All students' data entered" << std::endl;
            break;
        }
    }
    return 0;
}
