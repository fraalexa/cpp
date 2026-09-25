#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Memory address of string variable: " << &str << '\n'
              << "Memory address held by stringPTR:  " << stringPTR << '\n'
              << "Memory address held by stringREF:  " << &stringREF << "\n\n"
              << "Value of the string variable:      " << str << '\n'
              << "Value pointed to by stringPTR:     " << *stringPTR << '\n'
              << "Value pointed to by stringREF:     " << stringREF << '\n';

    return 0;
}