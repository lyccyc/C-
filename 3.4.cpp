#include <iostream>
#include <string>

using namespace std;

class ReverseAdd {
private:
    int num;
    int iterations;
    
    int reverseNumber(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    bool isPalindrome(int num) {
        int original = num;
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return original == rev;
    }

public:
    ReverseAdd(int n) : num(n), iterations(0) {}

    void findPalindrome() {
        do {
            int reversed = reverseNumber(num);
            num += reversed;
            iterations++;
        }while (!isPalindrome(num));
    }

    int getIterations() const {
        return iterations;
    }

    int getResultPalindrome() const {
        return num;
    }
};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num; 

        ReverseAdd ra(num);
        ra.findPalindrome();
        cout << ra.getIterations() << " " << ra.getResultPalindrome() << endl; 
    }

    return 0;
}
