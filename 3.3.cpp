#include <iostream>
#include <string>

using namespace std;
class Matrix{
private:
    int size;
    int **data;
    bool initialized;
public:
    Matrix(int n) : size(n) {
        // Dynamically allocate memory for the matrix
        data = new int*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
        }
    }

    ~Matrix() {
        // Free dynamically allocated memory
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void initialize() {
        initialized = true;
    }

    bool isInitialized() const {
        return initialized;
    }

    void rotateRight() {
        int** rotated = new int*[size];
        for (int i = 0; i < size; i++) {
            rotated[i] = new int[size];
            for (int j = 0; j < size; j++) {
                rotated[j][size - 1 - i] = data[i][j];
            }
        }
        // Free the original matrix
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = rotated;
    }

    void rotateLeft() {
        int** rotated = new int*[size];
        for (int i = 0; i < size; i++) {
            rotated[i] = new int[size];
            for (int j = 0; j < size; j++) {
                rotated[size - 1 - j][i] = data[i][j];
            }
        }
        // Free the original matrix
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = rotated;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    void scan() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> data[i][j];
            }
        }
    }
};

int main() {
    string instruction;
    Matrix matrix1(0),matrix2(0); 

    string right = "rotate right";
    string left =  "rotate left";
    while (true) {
        cin >> instruction;

        if (instruction == "scan") {
            int size;
            cin >> size;
            matrix2 = Matrix(size); 
            matrix2.scan();
        } 
        else if (instruction == "print") {
            if (matrix2 != matrix1){
                matrix2.print();
            }
            else{
                cout << "No element in matrix can be printed."<< endl;
            }
        } 
        else if (instruction.compare(right) == 0 ) {
            if(matrix2 != matrix1){
                matrix2.rotateRight();
            }
            else{
                cout <<"No element in matrix can be rotated."<< endl;
            }
        }
        else if (instruction.compare(left) == 0 ) {
            if(matrix2 != matrix1){
                matrix2.rotateLeft();
            }
            else{
                cout <<"No element in matrix can be rotated."<< endl;
            }
        }
        else if (instruction == "stop") {
            break;
        } 
        else {
            cout << "unknown" << endl;
        }
    }

    return 0;
}
