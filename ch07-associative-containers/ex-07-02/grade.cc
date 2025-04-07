#include "grade.h"

#include <stdexcept>
#include <vector>

#include "median.h"

using std::domain_error;
using std::vector;

// Calculates the final grade, provided a midterm grade, final exam grade, and a vector of homework grades
Grade grade(const double midterm, const double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

// Applies the correct weighting to the midterm grade, final exam grade, and overall homework grade to calculate final grade
Grade grade(const double midterm, const double final, const double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

LetterGrade letter_grade(Grade grade)
{
    if (grade < 60)
    {
        return 'F';
    }
    else if (grade < 70)
    {
        return 'D';
    }
    else if (grade < 80)
    {
        return 'C';
    }
    else if (grade < 90)
    {
        return 'B';
    }
    else
    {
        return 'A';
    }
}
