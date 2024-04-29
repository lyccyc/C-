#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
  Time() : hours(0), minutes(0), seconds(0) {};
  Time(string timeStr) {
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
        return abs(totalSeconds1 - totalSeconds2);
    }
};
