#include <iostream>
#include <iomanip>
#include "ClapTrap.hpp"
#include "includes/ClapTrap.hpp"


int main(void) {
    std::cout << "--- 1. Basic Actions ---" << std::endl;
    ClapTrap bob("Bob");
    ClapTrap alice("Alice");

    bob.attack("Alice");
    alice.takeDamage(5);
    alice.beRepaired(3);

    std::cout << "\n--- 2. Fatal Damage Edge Case ---" << std::endl;
    bob.takeDamage(30);
    bob.attack("Alice");
    bob.beRepaired(15);

    std::cout << "\n--- 3. Energy Exhaustion Edge Case ---" << std::endl;
    ClapTrap spammer("Spammer");
    for (int i = 0; i < 10; ++i) {
        spammer.beRepaired(1);
    }
    spammer.attack("Target");

    std::cout << "\n--- 4. Orthodox Canonical Form ---" << std::endl;
    ClapTrap original("Original");
    ClapTrap copy(original);
    ClapTrap
    assigned = original;

    std::cout << "\n--- 5. Destructors called below ---" << std::endl;
    return 0;
}
