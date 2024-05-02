#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    Point() : x(0),y(0){}

    Point(float xVal, float yVal) : x(xVal), y(yVal) {}

    void printPoint() const {
        cout << "(" << x << ", " << y << ")";
    }

    float getX() const { 
        return x;
    }
    void setX(float newX) { 
        x = newX; 
    }
    float getY() const { 
        return y; 
    }
    void setY(float newY) { 
        y = newY; 
    }

    float getDistance(const Point &other) const {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};
class Segment
{
private:
    Point point1;
    Point point2;

public:
    Segment() : point1(0, 0), point2(0, 0) {}

    Segment(const Point& p1, const Point& p2) : point1(p1), point2(p2) {}

    float getLength() const {
        return point1.getDistance(point2);
    }

    Point getPoint1() const { return point1; }
    Point getPoint2() const { return point2; }
};