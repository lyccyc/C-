#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int m) : numerator(n), denominator(m) {
        if(m == 0)
            throw "divided by zero";
        simplify();
    }
    int getNumerator() const {
        return numerator;
    }
    int getDenominator() const {
        return denominator;
    }
    void setNumerator(int n) {
        numerator = n;
        simplify();
    }
    void setDenominator(int m) {
        if(m == 0)
            throw "divided by zero";
        denominator = m;
        simplify();
    }

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

    friend ostream& operator<<(ostream& out, const Fraction &f) {
        if (f.denominator == 1 || f.numerator == 0)
            out << f.numerator;
        else
            out << "[" << f.numerator << "/" << f.denominator << "]";
        return out;
    }

private:
    int numerator, denominator;
};

int main() {
    int n1, n2, m1, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    Fraction f1(n1, m1), f2(n2, m2);
    cout << (f1 + f2) << endl;
    cout << (f1 - f2) << endl;
    cout << (f1 == f2) << endl;

    return 0;
}
