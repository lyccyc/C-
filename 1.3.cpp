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

class Triangle {
    private:
        Point point1;
        Point point2;
        Point point3;

    public:
    
        void setPoint1(double x, double y) { 
            point1.setX(x); point1.setY(y); 
        }
        void setPoint2(double x, double y) { 
            point2.setX(x); point2.setY(y); 
        }
        void setPoint3(double x, double y) { 
            point3.setX(x); point3.setY(y); 
        }
        double distance(Point &p1,Point &p2)  {
            double x1 = p1.getX();
            double y1 = p1.getY();
            double x2 = p2.getX();
            double y2 = p2.getY();
            return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        }

        double perimeter(){
            double side1=distance(point1,point2);
            double side2=distance(point2,point3);
            double side3=distance(point3,point1);
            return side1 + side2 + side3;
        }
};

int main() {
    int num;
    cin>>num;
    Triangle triangle;


    for(int i=0;i<num;i++){
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    triangle.setPoint1(x1,y1);
    triangle.setPoint2(x2,y2);
    triangle.setPoint3(x3,y3);
    }

    for(int i=0;i<num;i++){
    cout << triangle.perimeter();
    }

    return 0;
}
