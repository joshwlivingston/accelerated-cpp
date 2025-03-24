/*
Are the following definitions valid? Why or why not?
    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";

Ans: Yes, the definitions perform valid string concatentation due to hello, a std::string,
  being the first operand.
*/

#include <iostream>
#include <string>

int main()
{
  const std::string hello = "Hello";
  const std::string message = hello + ", world" + "!";
  std::cout << message << std::endl;
  return 0;
}
