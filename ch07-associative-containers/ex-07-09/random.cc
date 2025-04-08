#include "random.h"

#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>

using std::domain_error;
using std::string;
using std::vector;

// return a random integer in the range [0, n)
int nrand(const vector<string>::size_type n)
{
    if (n <= 0)
    {
        throw domain_error("n must be greater than 0");
    }

    int multiplier = n / RAND_MAX + 1;
    if (n % RAND_MAX != 0)
    {
        ++multiplier;
    }

    // due to integer division, RAND_MAX / n is the largest integer
    // that is less than or equal to the exact quotient
    const int bucket_size = RAND_MAX * multiplier / n;

    // rand() produces a random integer in [0, RAND_MAX]
    // division by bucket_size produces [0, (RAND_MAX * multiplier) / (n + (RAND_MAX * multipler) % n)]
    int r;
    do
        r = rand() * multiplier / bucket_size;
    while (r >= n);

    return r;
}
