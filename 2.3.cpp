class Path {
public:
    Path(Segment segments[], int num) {
        double pathLength = 0.0;
        pathLength += segments[0].length();
        for (int i = 1; i < num; i++) {
            if (segments[i - 1].getEnd(1).getX() != segments[i].getEnd(0).getX() ||
                segments[i - 1].getEnd(1).getY() != segments[i].getEnd(0).getY()) {
                cout << "-1" << endl;
                return ;
            }
            pathLength += segments[i].length();
        }
        if (segments[num-1].getEnd(1).getX() == segments[0].getEnd(0).getX() && 
            segments[num-1].getEnd(1).getY() == segments[0].getEnd(0).getY()) {
                cout << "-1" << endl;
                return ;
        }
      	cout <<pathLength << endl;
    }
};