#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {

    public :

        Point( void );
        Point( const Point& copy );
        Point& operator=(Point& rhs);
        ~Point( void );

        Point( const float x, const float y );

        const Fixed getX( void ) const;
        const Fixed getY( void ) const;

    private :

        const Fixed x;
        const Fixed y;
};

#endif