#pragma once
#include "Point.hpp"
#include <vector>
#include "Triangle.hpp"

class Polygon {
    private:
        std::vector<Point> points;
    public:
        Polygon(std::vector<Point> points);
        double area();
        double perimeter();
};