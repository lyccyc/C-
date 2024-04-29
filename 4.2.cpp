
Fraction operator+(const Fraction& a, const Fraction& b) {
        int num = a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator();
        int denom = a.getDenominator() * b.getDenominator();
        int common = __gcd(num,denom);
        return Fraction(num/common, denom/common);
    }

Fraction operator-(const Fraction& a, const Fraction& b) {
        int num = a.getNumerator() * b.getDenominator() - b.getNumerator() * a.getDenominator();
        int denom = a.getDenominator() * b.getDenominator();
        int common = __gcd(num,denom);
        return Fraction(num/common, denom/common);
    }

bool operator==(const Fraction& a, const Fraction& b) {
        return (a.getNumerator() * b.getDenominator()) == (b.getNumerator() * a.getDenominator());
    }