#include <iostream>
#include <cmath>
using namespace std;

class Tollway {
private:
    double distance;

public:
    Tollway(int _distance) : distance(_distance) {}

    double calculateToll() {
       double totalToll = 0;
        if (distance <= 200) {
            totalToll = round(distance * 1.2);
        } else {
            double first200KM = 200 * 1.2;
            double exceededToll =  round((distance - 200) * 1.2 * 0.75); 
            totalToll = first200KM + exceededToll;
        }
        return totalToll;
    }
};

int main() {
    double distance;
    cin >> distance;

    Tollway trip(distance);
    double totalToll = trip.calculateToll();

    cout <<totalToll << endl;

    return 0;
}
