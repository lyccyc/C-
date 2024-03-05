#include <iostream>
#include <cmath>
using namespace std;

class Segment {
private:
    double x1, y1, x2, y2;

public:
    // Setter methods for points
    void setPoint1(double x, double y) {
        x1 = x;
        y1 = y;
    }

    void setPoint2(double x, double y) {
        x2 = x;
        y2 = y;
    }

    // Function to calculate distance between two points
    static double distance(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
};

int main() {
    Segment segment;

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    // Set coordinates for points of the segment
    segment.setPoint1(x1, y1);
    segment.setPoint2(x2, y2);

    // Calculate and output the distance between the two points
    cout << Segment::distance(x1, y1, x2, y2) << endl;

    return 0;
}
