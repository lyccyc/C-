#include <iostream>
#include <cmath>

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
        int gcd = findGCD(std::abs(numerator), std::abs(denominator));
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
    int getNumerator() {
        return numerator;
    }

    // Getter for denominator
    int getDenominator() {
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

    // Display function
    void display() {
        if (denominator == 1) {
            std::cout << "(" << numerator << ")";
        } else {
            std::cout << "(" << numerator << "/" << denominator << ")";
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

    // Overloading * operator
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Overloading / operator
    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    // Overloading assignment operator
    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    // Overloading << operator
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        if (fraction.denominator == 1) {
            os << fraction.numerator;
        } else {
            os << "(" << fraction.numerator << "/" << fraction.denominator << ")";
        }
        return os;
    }

    // Overloading ! operator (return reciprocal of the fraction)
    Fraction operator!() const {
        return Fraction(denominator, numerator);
    }
};

int main() {
    Fraction a, b(1, 2), c(1, 3), d(1, 4), e(2, 5), f(2, 3);

    a = (((b + c) - d) * e) / f;

    std::cout << "a = " << a << std::endl;

    std::cout << "Reciprocal of a: " << !a << std::endl;

    return 0;
}
