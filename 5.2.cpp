#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date() : year(1900), month(1), day(1) {} // Default constructor

    Date(string dateStr) {
        sscanf(dateStr.c_str(), "%d/%d/%d", &year, &month, &day);
    }

    string toString() const {
        return to_string(year) + "/" + (month < 10 ? "0" : "") + to_string(month) + "/" + (day < 10 ? "0" : "") + to_string(day);
    }

    int operator-(const Date &other) const {
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = 0;
        
        // Calculate days in the full years
        for (int y = other.year; y < year; ++y) {
            days += isLeapYear(y) ? 366 : 365;
        }

        // Add days in the remaining months
        for (int m = 1; m < month; ++m) {
            days += daysInMonth[m];
            if (m == 2 && isLeapYear(year)) // Add an extra day for February if it's a leap year
                days++;
        }

        days += day; // Add days of the current month
        days -= other.day; // Subtract days of other date
        
        return days;
    }

private:
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main() {
    Date defaultDate;
    Date customDate("2024/04/27");

    cout << "Default Date: " << defaultDate.toString() << endl;
    cout << "Custom Date: " << customDate.toString() << endl;
    cout << "Difference in days: " << customDate - defaultDate << endl;

    return 0;
}
