#include <iostream>
#include <string>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat: Default constructor called!\n";
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type)
{
    std::cout << "WrongCat: String constructor called!\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat: Copy constructor called!\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat: Copy assignment operator called!\n";
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor called!\n";
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meow!\n";
}