#include <iostream>
#include <cmath>

using namespace std;

class Matrix{
private:
    int size;
    int** array = new int*[size]; 
public:

    //配置記憶體
    for(int i=0; i<size; i++){
        array[i] = new int[size]; //第二步
    }

    void scan(){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cin>>array[i][j];
            }
        }
    }

    int print(){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout<<array[i][j];
            }
        }
    }
    //釋放記憶體
    for(int i=0; i<size; i++){
        delete[] array[i]; //第一步
}

    delete[] array; //第二步
}