#include "students.h"

#include <stdexcept>

using std::domain_error;

/*
Rewriting the extract_fails function so that instead of erasing each failing
student from the input vector v, it copies the records for the passing students
to the beginning of v, and then uses the resize function to remove the extra
elements from the end of v.
*/
Students extract_fails(Students &students)
{
    Students fail;
    Students::size_type n_passing_students = 0;
    const Students::size_type n_students = students.size();
    Students::size_type start_index = 0;

    for (Students::size_type i = n_students; i != n_passing_students; --i)
    {
        try
        {
            if (fgrade(students[i]))
            {
                fail.push_back(students[i]);
            }
            else
            {
                students.insert(students.begin(), students[i]);
                ++i;
                ++n_passing_students;
            }
        }
        catch (domain_error &e)
        {
            fail.push_back(students[i]);
        }
    }

    students.resize(n_passing_students);
    return fail;
}
