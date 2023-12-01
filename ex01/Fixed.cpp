#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed( void ) : _fix(0) {

    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed( const Fixed& other ) {

    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return ;
}

Fixed::Fixed( const int value ) {

    std::cout << "Int constructor called" << std::endl;
    _fix = (value << _bits);
    return ;
}

Fixed::Fixed( const float value ) {

    std::cout << "Float constructor called" << std::endl;
    _fix = roundf(value * (1 << _bits));
    return ;
}

Fixed::~Fixed( void ) {

    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed& Fixed::operator=(const Fixed& other) {

    if (this != &other) {
        std::cout << "Copy assignment operator called" << std::endl;
        _fix = other.getRawBits();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &other) {

    os << other.toFloat();
    return (os);
}

int Fixed::getRawBits( void ) const {

    return _fix;
}

void Fixed::setRawBits( int const raw ) {

    _fix = raw;
    return ;
}

float   Fixed::toFloat( void ) const {

    return (float)(this->getRawBits()) / (float)(1 << this->_bits);
}

int     Fixed::toInt( void ) const {

    return _fix >> _bits;
}