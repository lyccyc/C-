#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

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

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date() : year(1900), month(1), day(1) {}

    Date(string dateStr) {
        stringstream ss(dateStr);
        char colon;
        ss >> year >> colon >> month >> colon >> day;
    }

    string toString() const {
        return to_string(year) + "/" + (month < 10 ? "0" : "") + to_string(month) + "/" + (day < 10 ? "0" : "") + to_string(day);
    }

    int operator-(const Date &other) const {
        int thisTotalDay = totalDays();
        int otherTotalDay = other.totalDays();
        return abs(thisTotalDay - otherTotalDay);
    }

    int countLeapYears(int year) const {
    int numLeapYear = 0;
        for (int i = 1900; i <= year; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
                numLeapYear++;
            }
        }
        if (month <= 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            numLeapYear--;
        }

        return numLeapYear;
}

    int totalDays() const {
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDays = day;

        totalDays += (year - 1900) * 365;

        for (int i = 1; i < month; ++i) {
            totalDays += days[i];
        }

        totalDays += countLeapYears(year);

        return totalDays;
    }
};

class DateTime {
public:
    DateTime() {}
    DateTime(const std::string& dateTimeStr) {
        sscanf(dateTimeStr.c_str(), "%d/%d/%d %d:%d:%d", &year, &month, &day, &hours, &minutes, &seconds);
    }
    std::string toString() const {
        stringstream ss;
        ss << year << "/"
           << setw(2) << setfill('0') << month << "/"
           << setw(2) << setfill('0') << day << " "
           << setw(2) << setfill('0') << hours << ":"
           << setw(2) << setfill('0') << minutes << ":"
           << setw(2) << setfill('0') << seconds;
        return ss.str();
    };
    //setw():設置寬度2;setfill():用0補齊空格;
    
private:
    int year = 1900;
    int month = 1;
    int day = 1;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
};

int main(){
    DateTime d1("1990/10/22 11:26:36");
    DateTime d2("1994/06/22 11:26:36");

    cout << d1.toString() << endl;
    cout << d2.toString() << endl;

    //cout << (d1-d2) << endl;

}
