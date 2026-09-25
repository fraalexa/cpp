#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
}

Zombie::~Zombie(void) {
}

void Zombie::setName(const std::string& name) {
    this->name_ = name;
}

void Zombie::announce(void) const {
    std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << "\n";
}