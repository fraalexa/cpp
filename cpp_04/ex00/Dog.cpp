#include <iostream>
#include <string>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog: Default constructor called!\n";
}

Dog::Dog(const std::string& type) : Animal(type)
{
    std::cout << "Dog: String constructor called!\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog: Copy constructor called!\n";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog: Copy assignment operator called!\n";
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called!\n";
}

void Dog::makeSound() const
{
    std::cout << "Dog: woof\n";
}