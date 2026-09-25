#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "=== 1. CONSTRUCTION / DESTRUCTION ORDER ===" << std::endl;
    {
        ScavTrap scav("Serena");
    }

    std::cout << "\n=== 2. SCAVTRAP ACTIONS & OVERRIDDEN ATTACK ===" << std::endl;
    ScavTrap scav("Serena");
    ClapTrap clap("Clappy");

    clap.attack("a target");
    scav.attack("a target");

    scav.takeDamage(30);
    scav.beRepaired(15);

    std::cout << "\n=== 3. SCAVTRAP SPECIAL ABILITY ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== 4. ORTHODOX CANONICAL FORM (COPY / ASSIGNMENT) ===" << std::endl;
    ScavTrap copyScav(scav);
    ScavTrap assignedScav;
    assignedScav = scav;

    std::cout << "\n=== 5. DESTRUCTORS AT EXIT ===" << std::endl;
    return 0;
}