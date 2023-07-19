#include "Polygon.hpp"
#include <vector>


Polygon::Polygon(std::vector<Point> points) {
      this->points = points;
}
double Polygon::area() {
      double polygon_area = 0;
      for(int i=1; i<points.size()-1; i++) {
        Triangle t(points[0], points[i], points[i+1]);
        polygon_area+=t.area();
      }
      return polygon_area;
    }
    double Polygon::perimeter() {
      double polygon_perimeter = 0;
      for(int i=0; i<points.size()-1; i++) {
        polygon_perimeter+=(this->points[i].distance_to_point(this->points[i+1]));
      }
      polygon_perimeter+=(this->points[this->points.size()-1].distance_to_point(this->points[0]));
      return polygon_perimeter;
    }
