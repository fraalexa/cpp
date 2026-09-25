#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "testing debug" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\ntesting info" << std::endl;
    harl.complain("INFO");

    std::cout << "\ntesting warning" << std::endl;
    harl.complain("WARNING");

    std::cout << "\ntesting error" << std::endl;
    harl.complain("ERROR");

    std::cout << "\ntesting invalid level" << std::endl;
    harl.complain("INVALID_LEVEL");

    return 0;
}