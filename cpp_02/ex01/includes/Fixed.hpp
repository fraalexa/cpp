#ifndef CPP_FIXED_HPP
#define CPP_FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 rawbits_;
    static const int    fractionalBits_ = 8;

public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    Fixed(const int value);
    Fixed(const float value);
    float toFloat(void) const;
    int   toInt(void) const;

    void setRawBits(int const raw);
    int  getRawBits(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& object);

#endif