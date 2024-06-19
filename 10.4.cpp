#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Minesweeper {
public:
    Minesweeper(int rows, int cols, const vector<string>& field) 
        : n(rows), m(cols), grid(field) {
        result = vector<string>(n, string(m, '0'));
    }

    void processField() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    result[i][j] = '*';
                    incrementAdjacentCells(i, j);
                }
            }
        }
    }

    void printField(int fieldNumber) const {
        cout << "Field #" << fieldNumber << ":\n";
        for (const auto& line : result) {
            cout << line << '\n';
        }
    }

private:
    int n, m;
    vector<string> grid;
    vector<string> result;

    void incrementAdjacentCells(int row, int col) {
        static const vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1}, { 0, 0}, { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        for (const auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (isInBounds(newRow, newCol) && result[newRow][newCol] != '*') {
                result[newRow][newCol]++;
            }
        }
    }
    //確認邊界
    bool isInBounds(int row, int col) const {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
};

int main() {
    int n, m, fieldNumber = 1;
    while (cin >> n >> m, n != 0 && m != 0) {
        vector<string> field(n);
        for (int i = 0; i < n; ++i) {
            cin >> field[i];
        }

        Minesweeper minesweeper(n, m, field);
        minesweeper.processField();
        if (fieldNumber > 1) {
            cout << '\n';
        }
        minesweeper.printField(fieldNumber);
        ++fieldNumber;
    }
    return 0;
}
