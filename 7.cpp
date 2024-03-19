#include <iostream>
using namespace std;
class ComplexNumber {
  double x, v;
public:
  ComplexNumber(double _x, double _v) : x(_x), v(_v) {}
  double getX() const {
    return x;
  }
  double getV() const {
    return v;
  }
  void setX(double _x) {
    x = _x;
  }
  void setV(double _v) {
    v = _v;
  }
  void display() {
    if(v > 0)
      cout << "(" << x << " + " << v << "i)";
    else
      cout << "(" << x << " - " << -v << "i)";
  }
  ComplexNumber operator+(const ComplexNumber a) const {
    return ComplexNumber(x + a.x, v + a.v);
  }
  //ComplexNumber operator++()  {
  //}
  //ComplexNumber operator++(int ) {
  //}
};

int main()
{
  ComplexNumber a(1, 2), b(3, 4);
  ComplexNumber c = a + b; // a.operator+(b)
  c.display();
}