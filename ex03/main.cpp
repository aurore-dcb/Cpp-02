#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);
int main() 
{
    Point point(3, 1);
    Point a(0, 0);
    Point b(2, 2);
    Point c(3, 0);
    if (bsp(a, b, c, point))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return (0);
}