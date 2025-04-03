#ifndef GUARD_students_h
#define GUARD_students_h

#include <vector>

#include "student_info.h"

typedef std::vector<StudentInfo> Students;

// students.cc
Students extract_fails(Students &);

#endif
