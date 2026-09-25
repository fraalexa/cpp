
#ifndef CPP_FIXED_HPP
#define CPP_FIXED_HPP
#include <iostream>

class Fixed {
    private:
        int					rawbits_;
        static const int	fractionalBits_ = 8;
    public:
        Fixed();
        Fixed(const Fixed& );
        ~Fixed();

    Fixed&	operator=( const Fixed& );
    void	setRawBits( int const raw );
    int		getRawBits( void ) const;
};

#endif //CPP_FIXED_HPP
