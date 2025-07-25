#include <chrono>
#include <list>

#include "mad_libs.h"

/*
On our benchmarking (10M iterations), we observe that lists are just under 10%
faster than vectors.

Input:
```
<noun>           cat
<noun>           dog
<noun>           table
<noun-phrase>    <noun>
<noun-phrase>    <adjective> <noun-phrase>
<adjective>      large
<adjective>      brown
<adjective>      absurd
<verb>           jumps
<verb>           sits
<location>       on the stairs
<location>       under the sky
<location>       wherever it wants
<sentence>       the <noun-phrase> <verb> <location>
```

Example Output:
```
Avg time (vector): 5970 nanoseconds
Avg time (list): 5555 nanoseconds
```
*/
int main()
{
    srand(time(0));
    static const std::chrono::steady_clock::time_point dummy =
        std::chrono::steady_clock::now();
    static const std::chrono::nanoseconds kZeroNanoseconds = dummy - dummy;
    static const int kNTimes = 10000000;

    // read input lines into grammar rule-set
    MadLibsRules mad_libs_rules;
    read(std::cin, mad_libs_rules);

    std::cout << "Directly streamed result: " << std::endl;
    generate_mad_libs<std::ostream_iterator<char>>(std::cout, mad_libs_rules);
    std::cout << std::endl;

    int i = 0;
    std::vector<std::chrono::nanoseconds> times_vec(kNTimes);
    while (i++ != kNTimes)
    {
        std::chrono::steady_clock::time_point start =
            std::chrono::steady_clock::now();

        std::vector<char> mad_libs;
        generate_mad_libs<std::back_insert_iterator<std::vector<char>>>(
            std::back_inserter(mad_libs), mad_libs_rules);

        std::chrono::steady_clock::time_point end =
            std::chrono::steady_clock::now();
        times_vec[i] = end - start;
        if (i == 0)
        {
            std::vector<char>::const_iterator it = mad_libs.begin();
            while (it != mad_libs.end())
                std::cout << *it++;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl
              << "Avg time (vector): "
              << ex0802::accumulate<
                     std::vector<std::chrono::nanoseconds>::const_iterator,
                     std::chrono::nanoseconds>(
                     times_vec.begin(), times_vec.end(), kZeroNanoseconds)
                         .count() /
                     kNTimes;

    i = 0;
    std::vector<std::chrono::nanoseconds> times_list(kNTimes);
    while (i++ != kNTimes)
    {
        std::chrono::steady_clock::time_point start =
            std::chrono::steady_clock::now();

        std::list<char> mad_libs_list;
        generate_mad_libs<std::back_insert_iterator<std::list<char>>>(
            std::back_inserter(mad_libs_list), mad_libs_rules);

        std::chrono::steady_clock::time_point end =
            std::chrono::steady_clock::now();
        times_list[i] = end - start;
        if (i == 0)
        {
            std::list<char>::const_iterator it = mad_libs_list.begin();
            while (it != mad_libs_list.end())
                std::cout << *it++;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl
              << "Avg time (list): "
              << ex0802::accumulate<
                     std::vector<std::chrono::nanoseconds>::const_iterator,
                     std::chrono::nanoseconds>(
                     times_list.begin(), times_list.end(), kZeroNanoseconds)
                         .count() /
                     kNTimes;

    i = 0;
    std::vector<std::chrono::nanoseconds> times_str(kNTimes);
    while (i++ != kNTimes)
    {
        std::chrono::steady_clock::time_point start =
            std::chrono::steady_clock::now();

        std::string mad_libs_str;
        generate_mad_libs<std::back_insert_iterator<std::string>>(
            std::back_inserter(mad_libs_str), mad_libs_rules);

        std::chrono::steady_clock::time_point end =
            std::chrono::steady_clock::now();
        times_str[i] = end - start;
        if (i == 0)
        {
            std::string::const_iterator it = mad_libs_str.begin();
            while (it != mad_libs_str.end())
                std::cout << *it++;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl
              << "Avg time (string): "
              << ex0802::accumulate<
                     std::vector<std::chrono::nanoseconds>::const_iterator,
                     std::chrono::nanoseconds>(
                     times_str.begin(), times_str.end(), kZeroNanoseconds)
                         .count() /
                     kNTimes;
}
