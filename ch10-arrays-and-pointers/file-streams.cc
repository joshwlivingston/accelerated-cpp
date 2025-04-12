/*
Accelerated C++: Section 10.05
Copy the contents of one file to another file
*/
#include <fstream>
#include <string>

int main()
{
    // in.txt must be polaced in same dir as executable
    std::ifstream input_file("in.txt");
    std::ofstream output_file("out.txt");
    std::string input_file_line;
    while (std::getline(input_file, input_file_line))
        output_file << input_file_line << std::endl;
    return 0;
}
