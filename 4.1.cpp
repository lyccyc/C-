#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Anagram : public string {
public:
    Anagram(const string& str) : string(str) {}

    
    bool operator==(const Anagram &other) const {
        string str1 = str;
        string str2 = other;
        return string == other.string;
    }
};

int main() {
  string buf;
  getline(cin, buf);
  Anagram a1(buf);
  getline(cin, buf);
  Anagram a2(buf);
  cout << a1 == a2;
  cout << a2 == a2;
}
