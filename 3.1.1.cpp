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
private:
    vector<Digit> value;
    vector<Digit> ans(1000,0);
public:
    Integer(const string& n) {
        int len = n.length();
        for (int i = 0; i < len; ++i) {
            value.push_back(Digit(n[len - 1 - i] - '0')); // Convert character to integer
        }
    }

    void displayInBase(int base) const {
        int count=0;
        for(int i=0;i<1000;i++){
            int num=value[i].getDigit();
            for(int j=0; num>0; j++){
                ans.push_back(num%base);
                num/=base;
                count++;
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0; i<count; i++){
            cout << ans[i];
        }   
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