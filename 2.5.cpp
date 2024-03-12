#include <iostream>
using namespace std;

class License{
private:
    int num;

public:
    
    License(int _num) : num(_num){}
    bool judge(){
        int digit;
        while (num > 0) {
            digit = num % 10;
            if (digit == 4) {
                return true;
            }
            num /= 10;
        }
        return false;
    }
};

int main(){
    int number;
    cin >> number;

    License plate(number);
    bool Four=plate.judge();

    if(Four){
        cout<<"Yes"<< endl;
    }
    else{
        cout<< "No"<< endl;
    }
}