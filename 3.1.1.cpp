#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Digit { // class Digit represent a digit in base 10
  int digit;
public:
  Digit(int d) : digit(d % 10) {}
  void setDigit(int d) { digit = d % 10; }
  int getDigit() const {return digit;}
};

class Integer { 
public:
    vector<Digit> value;
    Integer(const string& n) {
        int len = n.length();
        for (int i = 0; i < len; ++i) {
            value.push_back(Digit(n[len - 1 - i] - '0')); // Convert character to integer
        }
    }

    void displayInBase(int base) const {
        char *stop;
        char *num = &value[0];
        int ans=strtol(num,&stop,base);
        cout << ans;
    }
};

int main()
{
  string in;
  int j;
  cin >> in;
  Integer i(in);
  for(j = 2;j <= 16;j ++) {
    i.displayInBase(j);
    cout << endl;
  }
}