class Segment {
private:
    Point endpoint1, endpoint2;
public:
    Segment(Point p1, Point p2) : endpoint1(p1), endpoint2(p2) {}

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