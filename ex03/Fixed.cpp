#include "Fixed.hpp"

const int Fixed::_bits = 16;

// ------------ Constructors / Destructors ------------ //

Fixed::Fixed( void ) : _fix(0) {

    return ;
}

Fixed::Fixed( const Fixed& other ) {

    *this = other;
    return ;
}

Fixed::Fixed( const int value ) {

    _fix = value << _bits;
    return ;
}

Fixed::Fixed( const float value ) {

    _fix = roundf(value * (1 << _bits));
    return ;
}

Fixed::~Fixed( void ) {

    return ;
}

// ------------ Member fonctions ------------ //

int Fixed::getRawBits( void ) const {

    return _fix;
}

void Fixed::setRawBits( int const raw ) {

    _fix = raw;
    return ;
}

float   Fixed::toFloat( void ) const {

    return (float)(this->_fix) / (float)(1 << this->_bits);
}

int     Fixed::toInt( void ) const {

    return _fix >> _bits;
}

// ------------ Min / Max ------------ //

Fixed &Fixed::min(Fixed& v1, Fixed& v2) {

    if (v1 < v2)
        return (v1);
    else
        return (v2);
}

Fixed &Fixed::max(Fixed& v1, Fixed& v2) {

    if (v1 > v2)
        return (v1);
    else
        return (v2);
}

const Fixed &Fixed::min(const Fixed& v1, const Fixed& v2) {

    if (v1 < v2)
        return (v1);
    else
        return (v2);
}

const Fixed &Fixed::max(const Fixed& v1, const Fixed& v2) {

    if (v1 > v2)
        return (v1);
    else
        return (v2);
}

// ------------ Operator overloading ------------ //

std::ostream &operator<<(std::ostream &os, const Fixed &other) {

    os << other.toFloat();
    return (os);
}

Fixed& Fixed::operator=(const Fixed& rhs) {

    if (this != &rhs) {
        _fix = rhs.getRawBits();
    }
    return *this;
}

bool    Fixed::operator>(const Fixed& rhs) const {

    return (_fix > rhs.getRawBits());
}

bool    Fixed::operator<(const Fixed& rhs) const {

    return (_fix < rhs.getRawBits());
}

bool    Fixed::operator>=(const Fixed& rhs) const {

    return (_fix >= rhs.getRawBits());
}

bool    Fixed::operator<=(const Fixed& rhs) const {

    return (_fix <= rhs.getRawBits());
}

bool    Fixed::operator==(const Fixed& rhs) const {

    return (_fix == rhs.getRawBits());
}

bool    Fixed::operator!=(const Fixed& rhs) const {

    return (_fix != rhs.getRawBits());
}

Fixed   Fixed::operator+(const Fixed& rhs) const {

    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(const Fixed& rhs) const {

    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(const Fixed& rhs) const {

    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(const Fixed& rhs) const {

    if (this->toFloat() == 0 || rhs.toFloat() == 0)
        return (Fixed(0));
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++(){
    
    _fix++;
    return *this;
}

Fixed	&Fixed::operator--(){
    
    _fix--;
    return *this;
}

Fixed	Fixed::operator++(int){
    
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed	Fixed::operator--(int){
    
    Fixed temp(*this);
    operator--();
    return temp;
}