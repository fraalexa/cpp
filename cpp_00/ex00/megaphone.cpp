#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            for (std::string::size_type j = 0; j < arg.length(); ++j) {
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(arg[j])));
            }
        }
    }
    std::cout << '\n';
    return (0);
}