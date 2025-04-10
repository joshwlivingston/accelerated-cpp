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
    if (n <= 0 || n > RAND_MAX)
    {
        throw domain_error("n must be in [1, RAND_MAX]");
    }

    // due to integer division, RAND_MAX / n is the largest integer
    // that is less than or equal to the exact quotient
    const int bucket_size = RAND_MAX / n;

    // rand() produces a random integer in [0, RAND_MAX]
    // division by bucket_size produces [0, RAND_MAX / (n + RAND_MAX % n)]
    int r = rand() / bucket_size;
    while (r >= n)
    {
        // Result may equal or exceed specified n. Repeat until r is in [0, n)
        r = rand() / bucket_size;
    }

    return r;
}