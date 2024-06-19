#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    double distanceTo(const Point& other) const {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }
};

class Mountain {
private:
    vector<Point> points;
    
    static bool comparePoints(const Point& a, const Point& b) {
        return a.x < b.x;
    }

public:
    Mountain(const vector<Point>& points) : points(points) {
        sort(this->points.begin(), this->points.end(), comparePoints);
    }

    double calculateSunlitLength() {
        double totalLength = 0.0;
        Point highest = points.back();

        for (int i = points.size() - 2; i >= 0; --i) {
            if (points[i].y > highest.y) {
                double segmentLength = points[i].distanceTo(points[i + 1]);
                double verticalRise = points[i].y - highest.y;
                double totalRise = points[i].y - points[i + 1].y;
                totalLength += segmentLength * (verticalRise / totalRise);
                highest = points[i];
            }
        }

        return totalLength;
    }
};

int main() {
    int C;  // Number of test cases
    cin >> C;

    while (C--) {
        int N;  // Number of coordinates
        cin >> N;

        vector<Point> coordinates;
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            coordinates.emplace_back(x, y);
        }

        Mountain mountain(coordinates);
        double sunlitLength = mountain.calculateSunlitLength();

        cout << fixed << setprecision(2) << sunlitLength << endl;
    }

    return 0;
}
