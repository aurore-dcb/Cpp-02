#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed( void ) : _fix(0) {

    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed( void ) {

    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed( const Fixed& other ) {

    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return ;
}

Fixed& Fixed::operator=(const Fixed& other) {

    if (this != &other) {
        std::cout << "Copy assignment operator called" << std::endl;
        _fix = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;
    return _fix;
}

void Fixed::setRawBits( int const raw ) {

    _fix = raw;
    return ;
}