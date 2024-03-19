#include <iostream>

using namespace std;

class Foo {
public:
  //void setData(int d) {data = d;}
  int &getData() {return data;}
  void display() {
    cout << data;
  }
private:
  int data;
};

int main()
{
  Foo foo;
  foo.getData() = 100;
  foo.display();
}

