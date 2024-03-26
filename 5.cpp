/*#include <iostream>
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
}*/

#include <iostream>
#include <string>

int main() {
    std::string line;

    // 使用 std::getline() 读取一行文本
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, line);
    std::cout << "You entered: " << line << std::endl;

    // 使用 std::cin.getline() 读取一行文本
    std::cout << "Enter another line of text: ";
    std::cin.getline(&line[0], line.size());
    std::cout << "You entered: " << line << std::endl;

    return 0;
}
