#include "Point.hpp"
#include <iomanip>

#define GREEN       "\033[32m"
#define RED         "\033[31m"
#define RESET_COLOR "\033[0m"

bool bsp( Point const a, Point const b, Point const c, Point const point );

void display_sol(Point const a, Point const b, Point const c, Point const point ) {

    std::cout << "The point with coordinates (" << point.getX().toFloat() << "," << point.getY().toFloat() << ") ";
    if (bsp(a, b, c, point))
        std::cout << "is " << GREEN << "in" << RESET_COLOR << " the rectangle with coordinates :" << std::endl;
    else
        std::cout << "is " << RED << "out" << RESET_COLOR << " of the rectangle with coordinates :" << std::endl;
    std::cout << "  A(" << a.getX().toFloat() << "," << a.getY().toFloat() << ")" << std::endl;
    std::cout << "  B(" << b.getX().toFloat() << "," << b.getY().toFloat() << ")" << std::endl;
    std::cout << "  C(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")" << std::endl;
}

int main() 
{
    // 1 - au milieu
    Point point1(2, 1);
    Point a1(0, 0);
    Point b1(2, 2);
    Point c1(3, 0);
    display_sol(a1, b1, c1, point1);
    // 2 - loin a l'exterieur
    Point point2(10, -14);
    Point b2(-2, -2);
    display_sol(a1, b2, c1, point2);
    // 3 - sur une arrete
    Point point3(-1, -1);
    display_sol(a1, b2, c1, point3);
    // 4 - sur un sommet
    Point point4(0.5f, 2.00f);
    Point a4(-1.5, 0);
    Point b4(0.5, 2);
    Point c4(1.5, 0);
    display_sol(a4, b4, c4, point4);
    // 5 - tout juste a l'interieur
    Point point5(2, -0.0001);
    Point a5(0, -1);
    Point b5(0, 2);
    Point c5(3, -1);
    display_sol(a5, b5, c5, point5);
    return (0);
}