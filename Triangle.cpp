#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include <cmath>


Triangle::Triangle(Point pa, Point pb, Point pc) : p1(pa), p2(pb), p3(pc) {
    this->p1 = pa;
    this->p2 = pb;
    this->p3 = pc;
}

double Triangle::area() {
     Line side_a(p1, p2);
      Line side_b(p2, p3);
      Line side_c(p3, p1);

      double length_side_a = side_a.length();
      double length_side_b = side_b.length();
      double length_side_c = side_c.length();

      double semi_perimeter = (length_side_a + length_side_b + length_side_c) / 2;

      double area = sqrt(semi_perimeter *  (semi_perimeter - length_side_a) * (semi_perimeter - length_side_b) * (semi_perimeter - length_side_c));

      return area;
}


