#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
protected:
    std::string	type_;

public:
    Animal();
    Animal( const std::string& type );
    Animal( const Animal& other );
    Animal& operator=( const Animal& other );
    virtual ~Animal();

    std::string		getType( void ) const;
    virtual void	makeSound( void ) const = 0;
};

#endif