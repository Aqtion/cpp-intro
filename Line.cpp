#include "Line.hpp"
#include "Point.hpp"
#include <cmath>


Line::Line(Point pa, Point pb) : p1(pa), p2(pb) {
      this->p1 = p1;
      this->p2 = p2;
    }

    double Line::length() {
      return p1.distance_to_point(p2);
    }
    double Line::distance_to_point(Point p3) {
        double slope = (p2.y() - p1.y()) / (p2.x() - p1.x());
        double a = -slope;

        double line_y_intercept = (p2.x() - slope * p2.x());
        double c = -line_y_intercept;

        double numerator = (a * p3.x() + p3.x() +c);
        double denominator = sqrt(pow(a, 2) + 1);

        return abs(numerator / denominator); 
    }
