#include <iostream>
using namespace std;

class Point {
    private:
        double x;
        double y;

    public:
        // 建構子
        Point() {
            x = y = 0.0;
        }

        void setX(double newX) { 
            x = newX; 
        }
        void setY(double newY) { 
            y = newY; 
        }

        double getX() { 
            return x; 
        }
        double getY() { 
            return y; 
        }
};
int main(){
  
  int num;
  cin>>num;
  Point point[num];
  //double arr[num][2];
  for(int i=0;i<num;i++){
    double x,y;

    cin>>x>>y;

    point[i].setX(x);
    point[i].setY(y);
    cout<<"("<<point[i].getX()<<", "<<point[i].getY()<<")"<<endl;
    }
    
  return 0;
}