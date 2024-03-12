#include <iostream>
#include <vector>
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
public:
    Segment(Point p1, Point p2) : endpoint1(p1), endpoint2(p2) {}
    Point getEnd(int n) {
        return (n == 0) ? endpoint1 : endpoint2;
    }
    double length() {
        double dx = endpoint2.getX() - endpoint1.getX();
        double dy = endpoint2.getY() - endpoint1.getY();
        return sqrt(dx * dx + dy * dy);
    }

private:
    Point endpoint1, endpoint2;
};

class Path {
public:
    Path(Segment segments[], int numSegments) {
        // Check if the path can be constructed
        for (int i = 1; i < numSegments; ++i) {
            if (segments[i - 1].getEnd(1).getX() != segments[i].getEnd(0).getX() ||
                segments[i - 1].getEnd(1).getY() != segments[i].getEnd(0).getY()) {
                cout << "-1" << endl; // Display -1 if the path cannot be constructed
                return;
            }
        }

        // Calculate and display the length of the path
        double pathLength = 0.0;
        for (int i = 0; i < numSegments; ++i) {
            pathLength += segments[i].length();
        }
        cout << pathLength << endl;
    }
};

int main() {
    // Example usage
    Point p1(1.0, 2.0);
    Point p2(4.0, 6.0);
    Point p3(6.0, 8.0);

    Segment segments[2] = {Segment(p1, p2), Segment(p2, p3)};

    // Construct the path and display its length
    Path path(segments, 2);

    return 0;
}
