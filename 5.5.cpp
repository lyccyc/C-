#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Location {
    int street;
    int avenue;
};

struct Point {
    int street;
    int avenue;
};

class GridCity {
private:
    int streets;
    int avenues;
    vector<Location> friends;

public:
    GridCity(int S, int A, const vector<Location>& friends) : streets(S), avenues(A), friends(friends) {}

    Point findMeetingPoint() const {
        vector<int> streetCounts(streets + 1, 0);
        vector<int> avenueCounts(avenues + 1, 0);

        for (const auto& friendLoc : friends) {
            streetCounts[friendLoc.street]++;
            avenueCounts[friendLoc.avenue]++;
        }

        int medianStreet = findMedian(streetCounts);
        int medianAvenue = findMedian(avenueCounts);

        return {medianStreet, medianAvenue};
    }

private:
    int findMedian(const vector<int>& counts) const {
        int sum = 0;
        int median = 0;
        for (int i = 0; i < counts.size(); ++i) {
            sum += counts[i];
            if (sum * 2 >= friends.size()) {
                median = i;
                break;
            }
        }
        return median;
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int S, A, F;
        cin >> S >> A >> F;

        vector<Location> friends;
        for (int i = 0; i < F; ++i) {
            int street, avenue;
            cin >> street >> avenue;
            friends.push_back({street, avenue});
        }

        GridCity city(S, A, friends);
        Point meetingPoint = city.findMeetingPoint();

        cout << "(Street: " << meetingPoint.street << ", Avenue: " << meetingPoint.avenue << ")" << endl;
    }

    return 0;
}
