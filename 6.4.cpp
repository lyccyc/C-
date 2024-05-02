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

class Shape
{
public:
  Shape() : edgeCount(0) {};
    // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
  Shape(Segment *segments, int numSegments) : edgeCount(numSegments){
    if (numSegments > 10) {
        throw invalid_argument("Too many segments provided");
    }

    // Check if segments form a closed path
    if (numSegments < 3) {
        throw invalid_argument("A shape must have at least 3 segments");
    }

    for (int i = 0; i < numSegments; ++i) {
        seg[i] = segments[i];
    }

    // Check if the segments form a closed path
    Point startPoint = seg[0].getPoint1();
    Point endPoint = seg[numSegments - 1].getPoint2();
    if (startPoint.getX() != endPoint.getX() || startPoint.getY() != endPoint.getY()) {
        throw invalid_argument("Segments do not form a closed path");
    }
  };
  virtual float getArea() = 0;
  float getPerimeter();
  Segment &getSeg(int index)
  {
  	return seg[index];
  }
private:
  Segment seg[10];
  int edgeCount;
};
