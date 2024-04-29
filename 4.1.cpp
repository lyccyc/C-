#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Anagram : public string {
public:
    Anagram(const string& str) : string(str) {}
  
    static string toLower(string s) {
        for (char& c : s) {
            c = tolower(c);
        }
        return s;
    }

    static string removePunct(string s) {
        s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
        return s;
    }

    bool operator==(const Anagram& other) const {
        string word1 = toLower(*this);
        string word2 = toLower(other);

        word1.erase(remove(word1.begin(), word1.end(), ' '), word1.end());
        word2.erase(remove(word2.begin(), word2.end(), ' '), word2.end());
        word1 = removePunct(word1);
        word2 = removePunct(word2);

        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        return word1 == word2;
    }
};