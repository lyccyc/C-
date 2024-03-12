#include <iostream>
using namespace std;

class Point {
    private:
        double distance;
        double time;

    public:
        // 建構子
        Point() {
            distance = time = 0.0;
        }

        void setX(double newX) { 
            distance = newX; 
        }
        void setY(double newY) { 
            time = newY; 
        }

        double getX() { 
            return distance; 
        }
        double getY() { 
            return time; 
        }
};
int main(){

  Point point;

  double distance,time;

  cin>>distance>>time;

  point.setX(distance);
  point.setY(time);
  cout<<point.getX()/point.getY()<<endl;
    
  return 0;
}
