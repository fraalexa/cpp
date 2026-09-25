#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawbits_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : rawbits_(value << fractionalBits_) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : rawbits_(static_cast<int>(roundf(value * (1 << fractionalBits_)))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->rawbits_ = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->rawbits_) / (1 << fractionalBits_);
}

int Fixed::toInt() const {
    return this->rawbits_ >> fractionalBits_;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return rawbits_;
}

void Fixed::setRawBits(int const raw) {
    rawbits_ = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& object) {
    os << object.toFloat();
    return os;
}