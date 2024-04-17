#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Anagram : public string {
public:
    Anagram(const string& str) : string(str) {}

    string Judge(Anagram &str){
        string str1=str;
        str1.erase(remove_if(str1.begin(), str1.end(), isspace), str1.end());
        transform(str1.begin(), str1.end(), str1.begin(), tolower);

        sort(str1.begin(), str1.end());

        return str;
    }

    bool operator==(const Anagram &str) const{
        string str1 = Judge(str);
        string str2 = other.str;

        return str1 == str2;
    }


};
