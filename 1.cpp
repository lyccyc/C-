#include <iostream>

using namespace std;

//void foo(int &b) {
//  b++;
//}

int &bar() {
  static int a = 10;
  cout << "bar: " << a << endl;
  return a;
}

int main()
{
  //int a = 10;
  //int &r = a;
  //r = 100;
  //foo(a);
  //cout << a << endl;
  //foo(10);
  int &b = bar();
  cout << "main: " << b << endl;
  cout << "main: " << bar() << endl;
  b ++;
  cout << "main: " << b << endl;
  cout << "main: " << bar() << endl;
  bar() ++;
  cout << "main: " << b << endl;
}