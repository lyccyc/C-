#include <iostream>
using namespace std;
class Point {
  double x, y;
public:
  Point(double _x, double _y) : x(_x), y(_y) {}
  double getX() const {return x;}
  double getY() const {return y;}
};

bool operator==(Point &a, Point &b) {
  if(a.getX() == b.getX() && a.getY() == b.getY())
    return true;
  return false;
}

int main() {
  double x, y;
  Point *p1, *p2;
  cin >> x >> y;
  p1 = new Point(x, y);
  cin >> x >> y;
  p2= new Point(x, y);
  if(*p1 == *p2) { //operator==(*p1, *p2)
    cout << "overlay";
  }
}