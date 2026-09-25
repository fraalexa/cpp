#include <iostream>
#include <string>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->brain_ = new Brain();
    std::cout << "Dog: Default constructor called!\n";
}

Dog::Dog(const std::string& type) : Animal(type)
{
    this->brain_ = new Brain();
    std::cout << "Dog: String constructor called!\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->brain_ = new Brain(*other.brain_);
    std::cout << "Dog: Copy constructor called!\n";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog: Copy assignment operator called!\n";
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain_;
        this->brain_ = new Brain(*other.brain_);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called!\n";
    delete this->brain_;
}

void Dog::makeSound() const
{
    std::cout << "Dog: woof\n";
}

Brain* Dog::getBrain() const
{
    return this->brain_;
}