#include <iostream>
#include <vector>
using namespace std;

class Grid {
private:
    int M, N;
    vector<vector<char>> grid;

public:
    Grid(int m, int n) : M(m), N(n), grid(m, vector<char>(n)) {}

    void readGrid() {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
            }
        }
    }

    int findLargestSquare(int r, int c) {
        char centerChar = grid[r][c];
        int maxSize = 1; // The smallest square is the center character itself
        int size = 1;

        while (true) {
            // Check the boundaries for the next larger square
            if (r - size < 0 || r + size >= M || c - size < 0 || c + size >= N)
                break;

            // Check if all characters in the new border of the square are the same
            for (int i = -size; i <= size; ++i) {
                if (grid[r - size][c + i] != centerChar || grid[r + size][c + i] != centerChar ||
                    grid[r + i][c - size] != centerChar || grid[r + i][c + size] != centerChar) {
                    return maxSize;
                }
            }

            // Increase the size of the square
            maxSize = 2 * size + 1;
            ++size;
        }

        return maxSize;
    }
};

class TestCase {
private:
    int M, N, Q;
    Grid* grid;

public:
    TestCase(int m, int n, int q) : M(m), N(n), Q(q), grid(new Grid(m, n)) {}

    ~TestCase() {
        delete grid;
    }

    void process() {
        grid->readGrid();
        cout << M << " " << N << " " << Q << endl;

        for (int i = 0; i < Q; ++i) {
            int r, c;
            cin >> r >> c;
            int largestSquareSize = grid->findLargestSquare(r, c);
            cout << largestSquareSize << endl;
        }
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int M, N, Q;
        cin >> M >> N >> Q;
        TestCase testCase(M, N, Q);
        testCase.process();
    }

    return 0;
}
