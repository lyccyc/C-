#include <stdio.h>

#define MAX 100

void printField(char field[MAX][MAX], int n, int m, int fieldNum) {
    printf("Field #%d:\n", fieldNum);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                printf("*");
            } 
            else {
                printf("%c", field[i][j]);
            }
        }
        printf("\n");
    }
}

void calculateMines(char field[MAX][MAX], int n, int m) {
    static const int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},         { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    char result[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                result[i][j] = '*';
            } else {
                result[i][j] = '0';
            }
        }
    }

    // 計算相鄰地雷數
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                for (int k = 0; k < 8; k++) {
                    int newRow = i + directions[k][0];
                    int newCol = j + directions[k][1];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && result[newRow][newCol] != '*') {
                        result[newRow][newCol]++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            field[i][j] = result[i][j];
        }
    }
}

int main() {
    int n, m, fieldNum = 1;

    while (scanf("%d %d", &n, &m) == 2 && n > 0 && m > 0) {
        char field[MAX][MAX];

        for (int i = 0; i < n; i++) {
            scanf("%s", field[i]);
        }

        calculateMines(field, n, m);

        if (fieldNum > 1) {
            printf("\n");
        }
        printField(field, n, m, fieldNum);

        fieldNum++;
    }

    return 0;
}
