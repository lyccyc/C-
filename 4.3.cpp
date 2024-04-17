class Fraction {
private:
    int numerator;
    int denominator;

    int findGCD(int a, int b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }

   //最簡分數
    void simplify() {
        int gcd = findGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
		
      	//負號
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}


    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        simplify();
    }

    int getNumerator() {
        return numerator;
    }

    int getDenominator() {
        return denominator;
    }

    // Setter for numerator
    void setNumerator(int num) {
        numerator = num;
        simplify();
    }
  
    void setDenominator(int denom) {
        denominator = denom;
        simplify();
    }

    void display() {
        if (denominator == 1) {
            cout << "(" << numerator << ")";
        } else {
            cout << "(" << numerator << "/" << denominator << ")";
        }
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    
    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        if (fraction.denominator == 1) {
            os << fraction.numerator;
        } else {
            os << "(" << fraction.numerator << "/" << fraction.denominator << ")";
        }
        return os;
    }
};