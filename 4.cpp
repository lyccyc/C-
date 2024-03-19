#include <iostream>
using namespace std;

class Foo {
  int data;
public:
  void fun2() { data = 10;}
  void fun1() const { fun2(); }
};

int main()
{
  Foo foo;
  foo.fun1();
}