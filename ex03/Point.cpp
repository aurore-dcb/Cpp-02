#include "Point.hpp"

Point::Point( void ) : x(0), y(0) { }

Point& Point::operator=( Point& rhs ) {

    (void)rhs;
    return *this;
}

Point::Point( const float a, const float b ) : x(Fixed(a)), y(Fixed(b)) { }

Point::Point( const Point& other ) : x(other.getX()), y(other.getY()) { }

Point::~Point( void ) { }

const Fixed Point::getX( void ) const {

    return this->x;
}

const Fixed Point::getY( void ) const {

    return this->y;
}