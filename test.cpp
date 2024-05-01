#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Drawing {
private:
    int width;
    int height;
    vector<vector<int>> draw;
    stack<pair<int, int>> stk; // Stack for keeping track of positions

public:
    Drawing(int w, int h) : width(w), height(h) {
        draw.resize(h + 1, vector<int>(w * 2 + 1, 0));
    }

    void drawLine(int x1, int y1, int x2, int y2) {
        if (x1 == x2) { // Vertical line
            for (int y = min(y1, y2); y <= max(y1, y2); ++y) {
                draw[y][x1 * 2] = 1;
            }
        } else { // Horizontal line
            for (int x = min(x1, x2); x <= max(x1, x2); ++x) {
                draw[y1][x * 2 + 1] = 2;
            }
        }
    }

    void eraseLine(int x1, int y1, int x2, int y2) {
        if (x1 == x2) { // Vertical line
            for (int y = min(y1, y2); y <= max(y1, y2); ++y) {
                draw[y][x1 * 2] = 0;
            }
        } else { // Horizontal line
            for (int x = min(x1, x2); x <= max(x1, x2); ++x) {
                draw[y1][x * 2 + 1] = 0;
            }
        }
    }

    void executeCommands(int startX, int startY, int commands) {
        stk.push({startX, startY * 2 + 1});

        int count = commands;
        while (count > 0) {
            char c;
            cin >> c;
            pair<int, int> tmp = stk.top();
            int x = tmp.first;
            int y = tmp.second;

            if (c == 'U') {
                eraseLine(x, y, x + 1, y);
                stk.push({x + 1, y});
            } else if (c == 'D') {
                eraseLine(x, y, x - 1, y);
                stk.push({x - 1, y});
            } else if (c == 'L') {
                eraseLine(x, y, x, y - 2);
                stk.push({x, y - 2});
            } else if (c == 'R') {
                eraseLine(x, y, x, y + 2);
                stk.push({x, y + 2});
            } else if (c == 'F') {
                int num;
                cin >> num;
                vector<pair<int, int>> flipList;
                for (int i = 0; i < num; ++i) {
                    flipList.push_back(stk.top());
                    stk.pop();
                }
                for (int i = num - 1; i >= 0; --i) {
                    stk.push(flipList[i]);
                }
                count += num;
            }

            count--;
        }
    }

    void print() const {
        for (int i = height; i >= 0; --i) {
            for (int j = 0; j < width * 2 + 1; ++j) {
                if (i == height && j == width * 2) continue;
                if (draw[i][j] == 1) cout << "|";
                else if (draw[i][j] == 2) cout << "_";
                else cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    for (int t = 0; t < num_test_cases; ++t) {
        int m, n;
        cin >> m >> n;
        int startX, startY;
        cin >> startX >> startY;

        Drawing drawing(n, m);
        drawing.executeCommands(startY - 1, startX - 1, m * n - 1);

        drawing.print();

        if (t != num_test_cases - 1) cout << endl;
    }
    return 0;
}
