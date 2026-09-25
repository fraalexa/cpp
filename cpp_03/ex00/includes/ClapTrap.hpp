
#ifndef CPP_CLAPTRAP_HPP
#define CPP_CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:

    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    const std::string& getName() const;
    void setName(const std::string& name);

    int getHp() const;
    int getAd() const;
    void setAd(int ad);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
    std::string name_;
    int hitPoints_;
    int energyPoints_;
    int attackDamage_;
};

#endif //CPP_CLAPTRAP_HPP
