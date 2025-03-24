/*
Are the following definitions valid? Why or why not?
    const std::string exclam = "!";
    const std::string message = "Hello" + ", world" + exclam;

Ans: No, the expression is not valid as written, since "Hello" is a string literal, not a std::string
  Below is a valid implementation
*/

#include <iostream>
#include <string>

int main()
{
  const std::string exclam = "!";
  const std::string hello = "Hello";
  const std::string message = hello + ", world" + exclam;
  std::cout << message << std::endl;
  return 0;
}
