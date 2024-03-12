#include <iostream>
#include <cmath>
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

class Segment {
    private:
        Point point1;
        Point point2;

    public:
    
        void setPoint1(double x, double y) { 
            point1.setX(x); point1.setY(y); 
        }
        void setPoint2(double x, double y) { 
            point2.setX(x); point2.setY(y); 
        }

        double distance()  {
            double x1 = point1.getX();
            double y1 = point1.getY();
            double x2 = point2.getX();
            double y2 = point2.getY();
            return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        }
};

int main() {
    int num;
    cin>>num;
    Segment segment;

    for(int i=0;i<num;i++){
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    segment.setPoint1(x1,y1);
    segment.setPoint2(x2,y2);

    cout << segment.distance()<<endl;
    }


    return 0;
}
