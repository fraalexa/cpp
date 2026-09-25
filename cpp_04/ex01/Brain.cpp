#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain: Default constructor called!\n";
}

Brain::Brain( const Brain& other )
{
    std::cout << "Brain: Copy constructor called!\n";
    for (int i = 0; i < 100; ++i)
        this->ideas_[i] = other.ideas_[i];
}

Brain& Brain::operator=( const Brain& other )
{
    std::cout << "Brain: Assignment constructor called!\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas_[i] = other.ideas_[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain: Destructor called!\n";
}

void Brain::setIdea( int index, const std::string& idea )
{
    if (index >= 0 && index < 100)
        this->ideas_[index] = idea;
}

const std::string& Brain::getIdea( int index ) const
{
    static const std::string empty = "";

    if (index >= 0 && index < 100)
        return (this->ideas_[index]);
    return empty;
}