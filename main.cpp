#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"

using namespace std;


class Circle {
  public:
    int radius;
    double area() {
      return M_PI * (radius * radius);
    }
};


class AUV {
  private:
    string name;
    Point position;
    double depth;
    double heading;
    array<double, 3> speed;
    double angular_speed;

  public:
    AUV(string name, Point po, double depth, double heading, array<double, 3> speed, double angular_speed) : position(po) {
      this->name = name;
      this->position = po;
      this->depth = depth;
      this->heading = heading;
      this->speed = speed;
      this->angular_speed = angular_speed;
    }
    void step(const double &dt) {
      heading+=(angular_speed*dt);
      position.setX(position.x() + (speed[0]*dt));
      position.setY(position.y() + (speed[1]*dt));
      depth+=(speed[2]*dt);
    }
    void apply_acceleration(const array<double ,3> &acceleration, const double &dt) {
      speed[0]+=(acceleration[0]*dt);
      speed[1]+=(acceleration[1]*dt);
      speed[2]+=(acceleration[2]*dt);
    }
    void apply_angular_acceleration(const double &angular_acceleration, const double &dt) {
      angular_speed+=(angular_acceleration*dt);
    }
    Point getPosition() {
      return position;
    }
    array<double, 3> getSpeed() {
      return speed;
    }
    double getDepth() {
      return depth;
    }
    double getAngularSpeed() {
      return angular_speed;
    }
};

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int add(int x,int y) {
  return x + y;
}

int subtract(int x, int y) {
  return x-y;
}

int multiply(int x, int y) {
  return x*y;
}

int divide(int x, int y) {
  return x/y;
}

int main()
{
  cout << "Keshav Badrinath, Building 24 Room 115" << "\n";

  int x = 5;
  int y = 7;
  int z = 8;
  int w = 9;  
  int v = 35;
  cout << "The sum of " << x << " and " << y << " and " << z << " is " << x+y+z << "\n";
  cout << "The product of " << x << " and " << y << " and " << z << " and " << w << " is " << w*x*y*z << "\n";
  cout << "The division of " << x << " and " << y << " and " << v << " is " << v / x / y << "\n";

  // std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;

  Circle c;
  c.radius = 3;
  cout << "Area of the circle: " << c.area() << "\n";

  Point p1(1,1);
  Point p2(2, 4);
  Point p3(5,7);


  Line l(p1, p2);
  Triangle triangle(p1,p2,p3);

  Point v1(1,1);
  Point v2(2,4);
  Point v3(5,3);
  Point v4(6,1);
  Point v5(3,0.5);
  vector<Point> points;
  points.push_back(v1);
  points.push_back(v2);
  points.push_back(v3);
  points.push_back(v4);
  points.push_back(v5);

  Polygon polygon(points);

  cout << triangle.area() << "\n";
  cout << polygon.area() << "\n";
  cout << "perim: " << polygon.perimeter() << "\n";
  cout << l.distance_to_point(p3) << "\n";
  cout << l.length() << "\n";
  cout << p1.distance_to_point(p2) << "\n";
  cout << p2.distance_to_origin() << "\n";

  array<double,3> arr = {3,5,-2};
  Point p(0,0);
  AUV auv("the_best_auv", p, -5, 0, arr, -0.3);
  auv.step(0.2);
  cout << "x: " << auv.getPosition().x() << "\n";
  cout << "y: " << auv.getPosition().y() << "\n";
  cout << "z: " << auv.getDepth() << "\n";

  array<double,3> accel = {2.5, 3.7, -1.3};
  auv.apply_acceleration(accel, 0.3);
  cout << "foward speed: " << auv.getSpeed()[0] << "\n";
  cout << "lat speed: " << auv.getSpeed()[1] << "\n";
  cout << "vert speed : " << auv.getSpeed()[2] << "\n";
  cout << "angular speed: " << auv.getAngularSpeed() << "\n";

  auv.apply_angular_acceleration(0.7, 0.4);
  cout << "angular speed: " << auv.getAngularSpeed() << "\n";

  return 0; 
}