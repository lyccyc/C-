#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class NumberChecker {
public:
    NumberChecker(int num) : number(num) {}

    // 質數
    bool isPrime() const {
        if (number <= 1) return false;
        if (number == 2) return true; 
        if (number % 2 == 0) return false; 
        int sqrtn = sqrt(number);
        for (int i = 3; i <= sqrtn; i += 2) {
            if (number % i == 0) return false;
        }
        return true;
    }

    // 求反數
    int getReversedNumber() const {
        string str = to_string(number);
        reverse(str.begin(), str.end());
        return stoi(str); //轉為int
    }

    // 反質數
    bool isEmirp() const {
        if (!isPrime()) return false;
        int reversedNumber = getReversedNumber();
        if (reversedNumber != number) {
            NumberChecker reversedChecker(reversedNumber);
            return reversedChecker.isPrime();
        }
        return false;
    }

    // Function to get the number
    int getNumber() const {
        return number;
    }

private:
    int number;
};

int main() {
    int N;
    while (cin >> N) {
        NumberChecker checker(N);
        if (!checker.isPrime()) {
            cout << N << " is not prime." << endl;
        } else if (checker.isEmirp()) {
            cout << N << " is emirp." << endl;
        } else {
            cout << N << " is prime." << endl;
        }
    }
    return 0;
}
