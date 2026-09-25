#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :
    type_("WrongAnimal")
{
    std::cout << "WrongAnimal: Default constructor called!\n";
}

WrongAnimal::WrongAnimal(const std::string& t) :
    type_(t)
{
    std::cout << "WrongAnimal: String constructor called!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) :
    type_(other.type_)
{
    std::cout << "WrongAnimal: Copy constructor called!\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal: Copy assignment operator called!\n";
    if (this != &other)
    {
        type_ = other.type_;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor called!\n";
}

void	WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal: Generic WrongAnimal sound.\n";
}

std::string	WrongAnimal::getType() const
{
    return type_;
}