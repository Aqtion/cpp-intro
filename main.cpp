#include <iostream>
using namespace std;

int add(int x, int y);
int subtract(int x, int y);
int multiplty(int x, int y);
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

  return 0; 
}