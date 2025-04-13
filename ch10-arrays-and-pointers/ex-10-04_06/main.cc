#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#include "string_list.h"
#include "split.h"

int main()
{
    std::string s;
    std::size_t kStringListSize = 14;
    StringList string_list = StringList(kStringListSize);
    std::getline(std::cin, s);
    StringList::iterator current = string_list.begin();
    split<StringList::iterator>(s, current);
    while (current != string_list.end())
    {
        if (*current != "")
            std::cout << *current << std::endl;
        ++current;
    }

    return 0;
}
