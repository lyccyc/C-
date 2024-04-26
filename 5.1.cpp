#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
  Time() : hours(0), minutes(0), seconds(0) {};
  Time(string& timeStr) {
        stringstream ss(timeStr);
        char colon;
        ss >> hours >> colon >> minutes >> colon >> seconds;
    }

  string toString() const{
    stringstream ss;
        ss << setw(2) << setfill('0') << hours << ":"
           << setw(2) << setfill('0') << minutes << ":"
           << setw(2) << setfill('0') << seconds;
        return ss.str();
    };
    //setw():設置寬度2;setfill():用0補齊空格;
  
  int operator-(const Time &other) const{
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return totalSeconds1 - totalSeconds2;
    }
};

int main(){
    string inputTime;

    cin >> inputTime;
    Time t1(inputTime);
    cout<<t1.toString()<<endl;

    cin >> inputTime;
    Time t2(inputTime);
    cout<<t2.toString()<<endl;
    
    cout << (t2-t1) << endl;
    
    return 0;

}