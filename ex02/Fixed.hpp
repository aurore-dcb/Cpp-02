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

        static Fixed min(Fixed& v1, Fixed& v2);
        static Fixed max(Fixed& v1, Fixed& v2);

        static Fixed min(const Fixed& v1, const Fixed& v2);
        static Fixed max(const Fixed& v1, const Fixed& v2);

        Fixed&	operator=(const Fixed& rhs);
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

        Fixed	operator++();
        Fixed	operator++(int rhs);
        Fixed	operator--();
        Fixed	operator--(int rhs);

        int		getRawBits( void ) const;
        void	setRawBits( int const raw );
        float	toFloat( void ) const;
        int		toInt( void ) const;

    private :

        int					_fix;
        static const int	_bits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif