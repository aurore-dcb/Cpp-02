#include "Point.hpp"

/* True si le point est à l’intérieur du triangle. False dans le cas contraire */
bool bsp( Point const a, Point const b, Point const c, Point const point) {

    float Alpha, Beta, Gamma, DetT;
    //mettre en float les point
    float Ax = a.getX().getRawBits() >> 8;
    float Ay = a.getY().getRawBits() >> 8;
    float Bx = b.getX().getRawBits() >> 8;
    float By = b.getY().getRawBits() >> 8;
    float Cx = c.getX().getRawBits() >> 8;
    float Cy = c.getY().getRawBits() >> 8;

    float Px = point.getX().getRawBits() >> 8;
    float Py = point.getY().getRawBits() >> 8;

    DetT = (By - Cy) * (Ax - Cx) + (Cx - Bx) * (Ay - Cy);
    Alpha = ((By - Cy) * (Px - Cx) + (Cx - Bx) * (Py - Cy)) / DetT;
    Beta = ((Cy - Ay) * (Px - Cx) + (Ax - Cx) * (Py - Cy)) / DetT;
    Gamma = 1.0f - Alpha - Beta;

    return (Alpha >= 0.0f && Beta >= 0.0f && Gamma > 0.0f && Alpha <= 1.0f && Beta <= 1.0f && Gamma <= 1.0f);
}