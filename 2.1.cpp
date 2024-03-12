#include <iostream>
using namespace std;

class Point {
private:
    float x;
    float y;
    bool initialized; 
public:

    Point(float initialX, float initialY) : x(initialX), y(initialY), initialized(true) {}
    
    Point() {
            x = y = 0.0;
        }
        
    void setX(float newX) {
        x = newX;
        initialized = true; 
    }

    void setY(float newY) {
        y = newY;
        initialized = true; 
    }

    float getX() { 
        return x; 
    }
    float getY() { 
        return y; 
    }
};

int main() {
    int num;
    Point p;

    cin>>num;

    for(int i=0;i<num;i++){
        float x,y;

        cin>>x>>y;

        p.setX(x);
        p.setY(y);
        cout << "(" << p.getX() << ", " << p.getY() << ")" << endl;
    }

    return 0;
}
