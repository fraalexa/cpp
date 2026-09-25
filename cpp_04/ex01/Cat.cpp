#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->brain_ = new Brain();
    std::cout << "Cat: Default constructor called!\n";
}

Cat::Cat(const std::string& type) : Animal(type)
{
    this->brain_ = new Brain();
    std::cout << "Cat: String constructor called!\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->brain_ = new Brain(*other.brain_);
    std::cout << "Cat: Copy constructor called!\n";
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat: Copy assignment operator called!\n";
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain_;
        this->brain_ = new Brain(*other.brain_);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called!\n";
    delete this->brain_;
}

void Cat::makeSound() const
{
    std::cout << "Cat: meow\n";
}

Brain* Cat::getBrain() const
{
    return this->brain_;
}