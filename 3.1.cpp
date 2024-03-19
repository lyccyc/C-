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

class Integer { // class Integer represent a positive integer
private:
    Digit value[1000];

public:
    // Construct an integer in base 10 using a string.
    // This constructor will convert the given string to integer if possible.
    // Otherwise, it will convert the digit part in the prefix of the given string.
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

    // Default constructor will construct an Integer object with value 0.
    Integer() {
        for (int i = 0; i < 1000; ++i) {
            value[i] = Digit(0);
        }
    }

    // Display the value in the given base from 2 to 16.
    // Order of symbol as 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F.
    void displayInBase(int base) const {
        int i = 999;
        // Find the most significant non-zero digit
        while (i > 0 && value[i].getDigit() == 0) {
            i--;
        }

        // Convert the number to the given base and output
        while (i >= 0) {
            int temp = 0;
            int power = 1;
            for (int j = 0; j < 4; ++j) {
                temp += value[i].getDigit() * power;
                power *= 10;
                i--;
                if (i < 0) break;
            }
            string result = "";
            while (temp > 0) {
                int digit = temp % base;
                char digitChar = (digit < 10) ? digit + '0' : digit - 10 + 'A';
                result = digitChar + result;
                temp /= base;
            }
            cout << result;
        }
    }
};

int main() {
    string input;
    cout << "Enter a number (in base 10): ";
    cin >> input;

    Integer num(input);

    int base;
    cout << "Enter the base to display (2 to 16): ";
    cin >> base;

    cout << "Value in base " << base << ": ";
    num.displayInBase(base);
    cout << endl;

    return 0;
}
