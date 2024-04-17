#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Private function to find the greatest common divisor (GCD) of two numbers
    int findGCD(int a, int b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }

    // Private function to simplify the fraction
    void simplify() {
        int gcd = findGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;

        // Ensure the negative sign is on the numerator
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    // Default constructor
    Fraction() : numerator(0), denominator(1) {}

    // Parameterized constructor
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        simplify();
    }

    // Getter for numerator
    int getNumerator() const {
        return numerator;
    }

    // Getter for denominator
    int getDenominator() const {
        return denominator;
    }

    // Setter for numerator
    void setNumerator(int num) {
        numerator = num;
        simplify();
    }

    // Setter for denominator
    void setDenominator(int denom) {
        denominator = denom;
        simplify();
    }

    // Overloading + operator
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Overloading - operator
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Overloading == operator
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    /*// Display function
    void display() const {
        if (denominator == 1) {
            cout << numerator;
        } else {
            cout << "[" << numerator << "/" << denominator << "]";
        }
    }*/

    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        if (fraction.denominator == 1 || fraction.numerator == 0) {
            os << fraction.numerator;
        } 
        else {
            os << "[" << fraction.numerator << "/" << fraction.denominator << "]";
        }
        return os;
    }
};

int main()
{
  int n1, n2, m1, m2;
  cin >> n1 >> m1 >> n2 >> m2;
  Fraction f1(n1, m1), f2(n2, m2);
  cout << (f1 + f2) << endl;
  cout << (f1 - f2) << endl;
  cout << (f1 == f2) << endl;
}