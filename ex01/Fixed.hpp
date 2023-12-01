#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    public :

        Fixed( void );
        Fixed( const Fixed& other );
        Fixed( const int value );
        Fixed( const float value );
        ~Fixed( void );
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

    private :

        int _fix;
        static const int _bits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif