#include "Fixed.hpp"
#include <iostream>

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << std::endl << "----- More tests ----" << std::endl;
    // + de tests
    //division par 0
    Fixed const c( Fixed(5.0f) / Fixed(0));
    std::cout << c << std::endl;
    // pre/post incrementation
    std::cout << "a: " << a << std::endl;
    a++;
    std::cout << "a: " << a << std::endl;
    a--;
    std::cout << "a: " << a << std::endl;
    std::cout << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "min: " << Fixed::min( a, b ) << std::endl;
    std::cout << "max: " << Fixed::max( a, b ) << std::endl;
    return 0;
}