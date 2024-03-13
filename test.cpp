class Path {
public:
    Path(Segment segments[], int num) {
        double pathLength = 0.0;
        for (int i = 1; i < num; i++) {
            if (segments[i - 1].getEnd(1).getX() != segments[i].getEnd(0).getX() ||
                segments[i - 1].getEnd(1).getY() != segments[i].getEnd(0).getY()) {
                cout << "-1" << endl;
                return ;
            }
            else{
                pathLength += segments[0].length();
                pathLength += segments[i].length();
                pathLength += segments[num].length();
                cout << pathLength << endl;
            }
        }
    }
};