#include <iostream>
#include <string>
#include <sstream>
using namespace std;

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

int main(){
    Date d1("1990/10/22");
    Date d2("1994/06/22");

    cout << d1.toString() << endl;
    cout << d2.toString() << endl;

    cout << (d1-d2) << endl;

}