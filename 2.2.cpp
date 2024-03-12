#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    Point(double _x, double _y) : x(_x), y(_y) {}
    double getX() { return x; }
    double getY() { return y; }

private:
    double x, y;
};

class Segment {
private:
    Point endpoint1, endpoint2;
public:
    Segment(Point p1, Point p2) : endpoint1(p1), endpoint2(p2) {}

    // Function to calculate length of the segment
    double length() {
        double dx = endpoint2.getX() - endpoint1.getX();
        double dy = endpoint2.getY() - endpoint1.getY();
        return sqrt(dx * dx + dy * dy);
    }

    Point getEnd(int value) {
        if (value == 0)
            return endpoint1;
        else
            return endpoint2;
    }

};

int main() {
    // Create two points
    Point p1(1.0, 2.0);
    Point p2(4.0, 6.0);

    // Create a segment with the two points
    Segment segment(p1, p2);

    // Calculate and output the length of the segment
    cout << "Length of the segment: " << segment.length() << endl;

    // Get one of the endpoints of the segment and output its coordinates
    Point endpoint = segment.getEnd(0);
    cout << "Endpoint 1: (" << endpoint.getX() << ", " << endpoint.getY() << ")" << endl;

    // Get the other endpoint of the segment and output its coordinates
    endpoint = segment.getEnd(1);
    cout << "Endpoint 2: (" << endpoint.getX() << ", " << endpoint.getY() << ")" << endl;

    return 0;
}
