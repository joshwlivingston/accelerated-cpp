#include "grade.h"

#include <stdexcept>
#include <vector>

#include "median.h"

using std::domain_error;
using std::vector;

double grade(const double midterm, const double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

double grade(const double midterm, const double final, const double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}