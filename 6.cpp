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
};

ComplexNumber operator+(const ComplexNumber &c, const ComplexNumber &d) {
  ComplexNumber *r = new ComplexNumber(c.getX() + d.getX(), c.getV() + d.getV());
  return *r;
}

ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b) {
  ComplexNumber *r = new ComplexNumber(a.getX() - b.getX(), a.getV() - b.getV());
  return *r;
}

ComplexNumber operator++(ComplexNumber &a) {
  a.setX(a.getX() + 1);
  return a;
}

ComplexNumber operator++(ComplexNumber &a, int) {
  a.setV(a.getV() + 1);
  return a;
}

int main()
{
  ComplexNumber a(1, 2), b(3, 4);
  ComplexNumber c = a + b; // operator+(a,b)
  c.display();
  a ++;
  operator++(a, 100);
  //++ a;
  a.display();
}