
#include "Fixed.hpp"

Fixed::Fixed() : rawbits_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed&	Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->rawbits_ = other.getRawBits();
    }
    return *this;
}

void	Fixed::setRawBits( int const raw ) {
    rawbits_ = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return rawbits_;
}