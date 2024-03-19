#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Digit { // class Digit represent a digit in base 10
private:
    int digit;

public:
    Digit(int d) : digit(d % 10) {}
    void setDigit(int d) { digit = d % 10; }
    int getDigit() const { return digit; }
};

class Integer { //class Integer represent a integer
private:
    Digit value[1000];
    bool sign;

public:
    //construct an integer in base 10 using a string.
    //This constructor will convert the given string to integer if possible.
    //Otherwise it will convert the digit part in prefix of the given string.
    Integer(string n) {
        int len = n.length();
        int startIndex = 0;

        // Iterate through the string and convert digits to integer
        int j = 0;
        for (int i = len - 1; i >= startIndex; --i) {
            if (isdigit(n[i])) {
                value[j++] = Digit(n[i] - '0');
            }
        }

        // Fill the remaining digits with 0
        for (; j < 1000; ++j) {
            value[j] = Digit(0);
        }
    }

    //default constructor will construct an Integer object with value 0.
    Integer() {
        for (int i = 0; i < 1000; ++i) {
            value[i] = Digit(0);
        }
        sign = false; // Initialize sign to positive
    }

    //function addition will add up two integer and return a new Integer object as result.
    Integer addition(const Integer &b) const {
        Integer result;
        int carry = 0;
        for (int i = 0; i < 1000; ++i) {
            int sum = value[i].getDigit() + b.value[i].getDigit() + carry;
            result.value[i] = Digit(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    //function subtraction will minus b from current object and return a new Integer object as result.
    Integer subtraction(const Integer &b) const {
        Integer result;
        int borrow = 0;
        for (int i = 0; i < 1000; ++i) {
            int diff = value[i].getDigit() - b.value[i].getDigit() - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.value[i] = Digit(diff);
        }
        return result;
    }

    // Function to display the Integer
    void display() const {
        int i = 999;
        // Find the most significant non-zero digit
        while (i > 0 && value[i].getDigit() == 0) {
            i--;
        }

        // Print the sign if negative
        if (sign)
            cout << "-";

        // Print the digits
        while (i >= 0) {
            cout << value[i].getDigit();
            i--;
        }
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    Integer num1(a), num2(b);
    num1.addition(num2).display();
    cout << endl;
    num2.addition(num1).display();
    cout << endl;
    num1.subtraction(num2).display();
    cout << endl;
    num2.subtraction(num1).display();
    cout << endl;

    return 0;
}
