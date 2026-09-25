#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Fragex") {
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap default constructor called for " << name_ << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap string constructor called for " << name_ << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    std::cout << "FragTrap copy constructor called for " << name_ << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& copy) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &copy) {
        ClapTrap::operator=(copy);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << name_ << std::endl;
}

void FragTrap::highFivesConformity(void) {
    if (hitPoints_ <= 0) {
        std::cout << "FragTrap " << name_ << " cannot request a high five (is dead)!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << name_ << " requests a high five!" << std::endl;
}