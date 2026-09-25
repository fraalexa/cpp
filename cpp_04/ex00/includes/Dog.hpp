#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog( const std::string& type );
    Dog( const Dog& other );
    Dog& operator=( const Dog& other );
    virtual ~Dog();

    virtual void	makeSound( void ) const;
};

#endif