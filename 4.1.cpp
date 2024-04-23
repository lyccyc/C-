#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Anagram {
private:
    unordered_map<char, int> charCount;

public:
    // Constructor
    Anagram(const string& str) {
        for (char c : str) {
            if (isalpha(c)) { // 只計算字母
                charCount[tolower(c)]++; // 將字母轉為小寫後計數
            }
        }
    }

    // Overloading == operator
    bool operator==(const Anagram& other) const {
        return charCount == other.charCount;
    }
};

int main() {
  string buf;
  getline(cin, buf);
  Anagram a1(buf);
  getline(cin, buf);
  Anagram a2(buf);
  cout << (a1 == a2) << endl;
  cout << (a2 == a1) << endl;

  return 0;
}
