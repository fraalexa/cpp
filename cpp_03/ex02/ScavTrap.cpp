#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Scavex") {
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap default constructor called for " << name_ << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap string constructor called for " << name_ << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called for " << name_ << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << name_ << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints_ <= 0 || energyPoints_ <= 0) {
        std::cout << "ScavTrap " << name_ << " cannot attack (no HP or EP left)!" << std::endl;
        return;
    }
    energyPoints_--;
    std::cout << "ScavTrap " << name_ << " fiercely attacks " << target
              << ", causing " << attackDamage_ << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    if (hitPoints_ <= 0) {
        std::cout << "ScavTrap " << name_ << " cannot enter Gate keeper mode (is dead)!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode!" << std::endl;
}

