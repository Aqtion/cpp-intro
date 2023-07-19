#pragma once
#include "Point.hpp"

class Triangle {
    private:
        Point p1;
        Point p2;
        Point p3;
    public:
        Triangle(Point p1, Point p2, Point p3);
        double area();
    
};
