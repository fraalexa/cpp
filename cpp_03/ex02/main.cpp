#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void) {
    ClapTrap clap("Clap");
    FragTrap frag("Frag");

    clap.attack("a dummy target");
    frag.attack("a dummy target");

    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesConformity();

    std::cout << "\n--- Death Edge Case ---" << std::endl;
    frag.takeDamage(100);
    frag.attack("a dummy target");
    frag.highFivesConformity();

    std::cout << "\n--- Destruction ---" << std::endl;
    return 0;
}