#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawbits_(0) {}

Fixed::Fixed(const int value) 
    : rawbits_(value << fractionalBits_) {}

Fixed::Fixed(const float value) 
    : rawbits_(static_cast<int>(roundf(value * (1 << fractionalBits_)))) {}

Fixed::Fixed(const Fixed& copy) {
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->rawbits_ = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

float Fixed::toFloat() const {
    return static_cast<float>(this->rawbits_) / (1 << fractionalBits_);
}

int Fixed::toInt() const {
    return this->rawbits_ >> fractionalBits_;
}

int Fixed::getRawBits() const {
    return rawbits_;
}

void Fixed::setRawBits(int const raw) {
    rawbits_ = raw;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->rawbits_ > other.rawbits_;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->rawbits_ < other.rawbits_;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->rawbits_ >= other.rawbits_;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->rawbits_ <= other.rawbits_;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->rawbits_ == other.rawbits_;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->rawbits_ != other.rawbits_;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return (other.toFloat() == 0.0f) ? Fixed(0) : Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    this->rawbits_++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->rawbits_++;
    return temp;
}

Fixed& Fixed::operator--() {
    this->rawbits_--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->rawbits_--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& object) {
    os << object.toFloat();
    return os;
}