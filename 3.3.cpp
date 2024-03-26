#include <iostream>
#include <vector>
#include <cstring> // 为了使用 strcmp() 函数
using namespace std;

class Matrix{
private:
    vector<vector<int>> matrix;
    int size;

public:
    Matrix(int n) : size(n) {
        matrix.resize(n, vector<int>(n, 0));
    }

    void rotateRight() {
        vector<vector<int>> tempMatrix = matrix;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[j][size - 1 - i] = tempMatrix[i][j];
            }
        }
    }

    void rotateLeft() {
        vector<vector<int>> tempMatrix = matrix;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[size - 1 - j][i] = tempMatrix[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void scan() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cin >> matrix[i][j];
            }
        }
    }
};

int main(){
    Matrix matrix(0);
    bool initialized=false;
    char instruction[50];

    while(true){
        cin.getline(instruction, 50);
        
        if(strcmp(instruction, "scan") == 0){
            int size;
            cin >> size;
            matrix=Matrix(size);
            matrix.scan();
            initialized=true;
        }

        else if(strcmp(instruction, "rotate right") == 0){
            if(initialized == true){
                matrix.rotateRight();
            }
            else{
                cout << "No element in matrix can be rotated."<< endl;
            }
        }
        
        else if(strcmp(instruction, "rotate left") == 0){
            if(initialized == true){
                matrix.rotateLeft();
            }
            else{
                cout << "No element in matrix can be rotated."<< endl;
            }
        }

        else if(strcmp(instruction, "print") == 0){
            if(initialized == true){
                matrix.print();
            }
            else{
                cout << "No element in matrix can be printed."<< endl;
            }
        }

        else if(strcmp(instruction, "stop") == 0){
            break;
        }

        else{
            cout << "unknown"<< endl;
        }
    }
    return 0;
}
