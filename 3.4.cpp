#include <iostream>
#include <string>
//#include <algorithm>

using namespace std;

class ReverseAdd {
private:
    int num;
    int iterations;
    
    // Function to reverse a number
    int reverseNumber(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    // Function to check if a number is a palindrome
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

    // Function to find the palindrome using the "reverse and add" method
    void findPalindrome() {
        while (!isPalindrome(num)) {
            int reversed = reverseNumber(num);
            num += reversed;
            iterations++;
        }
    }

    // Function to get the number of iterations
    int getIterations() const {
        return iterations;
    }

    // Function to get the resulting palindrome
    int getResultPalindrome() const {
        return num;
    }
};

int main() {
    int n;
    cin >> n; // 输入数字个数

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num; // 输入数字

        ReverseAdd ra(num);
        ra.findPalindrome();
        cout << ra.getIterations() << " " << ra.getResultPalindrome() << endl; // 输出迭代次数和结果回文数
    }

    return 0;
}
