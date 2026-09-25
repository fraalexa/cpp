#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {}

void Zombie::announce() const{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}