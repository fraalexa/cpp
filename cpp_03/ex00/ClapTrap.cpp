#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name_("Default"), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
    std::cout << "ClapTrap default constructor called for " << name_ << "\n";
}

ClapTrap::ClapTrap(const std::string& name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
    std::cout << "ClapTrap string constructor called for " << name_ << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_), hitPoints_(other.hitPoints_),
      energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_) {
    std::cout << "ClapTrap copy constructor called for " << name_ << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator called\n";
    if (this != &other) {
        name_ = other.name_;
        hitPoints_ = other.hitPoints_;
        energyPoints_ = other.energyPoints_;
        attackDamage_ = other.attackDamage_;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << name_ << "\n";
}

const std::string& ClapTrap::getName() const {
    return name_;
}

void ClapTrap::setName(const std::string& name) {
    name_ = name;
}

int ClapTrap::getHp() const {
    return hitPoints_;
}

int ClapTrap::getAd() const {
    return attackDamage_;
}

void ClapTrap::setAd(int ad) {
    attackDamage_ = ad;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints_ <= 0 || energyPoints_ <= 0) {
        std::cout << "ClapTrap " << name_ << " cannot attack (no HP or EP left)!\n";
        return;
    }
    energyPoints_--;
    std::cout << "ClapTrap " << name_ << " attacks " << target
              << ", causing " << attackDamage_ << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints_ <= 0) {
        std::cout << "ClapTrap " << name_ << " is already down!\n";
        return;
    }

    if (amount >= static_cast<unsigned int>(hitPoints_))
        hitPoints_ = 0;
    else
        hitPoints_ -= amount;

    std::cout << "ClapTrap " << name_ << " took " << amount
              << " damage! Remaining HP: " << hitPoints_ << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints_ <= 0 || energyPoints_ <= 0) {
        std::cout << "ClapTrap " << name_ << " cannot be repaired (no HP or EP left)!\n";
        return;
    }
    energyPoints_--;
    hitPoints_ += amount;
    std::cout << "ClapTrap " << name_ << " repairs itself for " << amount
              << " hit points! Current HP: " << hitPoints_ << "\n";
}