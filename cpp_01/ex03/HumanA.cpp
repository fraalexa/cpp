#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name_(name), weapon_(weapon) {}

HumanA::~HumanA(){};

void HumanA::attack() const {
    std::cout << name_ << " attacks with their "
              << weapon_.getType() << '\n';
}