#include "Animal.hpp"

Animal::Animal() : type_("Animal") {
    std::cout << "Animal: Default constructor called!" << std::endl;
}

Animal::Animal( const std::string& type ) : type_(type) {
    std::cout << "Animal: Parameterized constructor called!" << std::endl;
}

Animal::Animal( const Animal& other ) : type_(other.type_) {
    std::cout << "Animal: Copy constructor called!" << std::endl;
}

Animal& Animal::operator=( const Animal& other ) {
    std::cout << "Animal: Copy assignment operator called!" << std::endl;
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called!" << std::endl;
}

std::string Animal::getType( void ) const {
    return this->type_;
}
/*
void Animal::makeSound( void ) const {
    std::cout << "Animal: Generic animal sound!" << std::endl;
}*/