#include "Point.hpp"

float ft_abs(const float f) {

    return (f < 0 ? -f : f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    float Alpha, Beta, Gamma, total;

    float Ax = a.getX().toFloat();
    float Ay = a.getY().toFloat();
    float Bx = b.getX().toFloat();
    float By = b.getY().toFloat();
    float Cx = c.getX().toFloat();
    float Cy = c.getY().toFloat();
    float Px = point.getX().toFloat();
    float Py = point.getY().toFloat();

    Alpha = 0.5 * ft_abs(Ax * (Py - By) + Px * (By - Ay) + Bx * (Ay - Py));
    Beta = 0.5 * ft_abs(Bx * (Py - Cy) + Px * (Cy - By) + Cx * (By - Py));
    Gamma = 0.5 * ft_abs(Cx * (Py - Ay) + Px * (Ay - Cy) + Ax * (Cy - Py));
    total = 0.5 * ft_abs(Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By));

    return ((Alpha + Beta + Gamma) == total && Alpha != 0 && Beta != 0 && Gamma != 0);
}