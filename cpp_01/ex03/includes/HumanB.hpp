#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name_;
    Weapon* weapon_;

public:
    explicit HumanB(const std::string& name);
    ~HumanB();

    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif // HUMAN_B_HPP