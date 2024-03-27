#include <iostream>
#include <vector>
#include <string>

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
    string instruction;
    int size;
    //char instruction[50];
    while(true){
        getline(cin,instruction);
        //cout << instruction << " ddd " << endl;
        //cin.getline(instruction,50);

        if(instruction == "scan"){
            cin >> size;
            //cout << size << " sss " << endl;
            matrix=Matrix(size);
            

            printf ("after scan:/n");
            matrix.print();


            if(size > 0){
                matrix.scan();
                cin.ignore();
                initialized=true;
            }
        }

        else if(instruction == "rotate right"){
            if(initialized == true){
                matrix.rotateRight();
            }
            else{
                cout << "No element in matrix can be rotated."<< endl;
            }
        }
        
        else if(instruction == "rotate left"){
            if(initialized == true){
                matrix.rotateLeft();
            }
            else{
                cout << "No element in matrix can be rotated."<< endl;
            }
        }

        else if(instruction == "print"){
            if(initialized == true){
                matrix.print();
                cout << endl;
            }
            else{
                cout << "No element in matrix can be printed."<< endl;
            }
        }

        else if(instruction == "stop"){
            break;
        }

        else{
            cout << "unknown"<< endl;
        }
    }
    return 0;
}
