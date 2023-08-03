#ifndef DATE_H
#define DATE_H

#include <bits/stdc++.h>

using namespace std;
bool validateThroughLib(string date);
bool validateWithStream(string date);
bool validate(int a, int b, int c);
class Date
{
private:
    int day = 0;
    int month = 0;
    int year = 9999;

public:
    // CONSTRUCTTORS
    Date(const int day = 0, const int month = 0, const int year = 9999)
    {
        if (validate(day, month, year))
        {
            this->day = day;
            this->month = month;
            this->year = year;
            return;
        }
        else
        {
            this->day = 0;
            this->month = 0;
            this->year = 9999;
            return;
        }
    }

    Date(const std::string date)
    {
        int day = 0, month = 0, year = 9999;
        if (validateThroughLib(date) && validateWithStream(date))
        {
            std::stringstream ss(date);
            char delimiter;
            ss >> day >> delimiter >> month >> delimiter >> year;
            this->day = day;
            this->month = month;
            this->year = year;
            return;
        }
        this->day = day;
        this->month = month;
        this->year = year;
    }
    friend std::ostream &operator<<(std::ostream &os, const Date &date)
    {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }
    // COPY CONSTRUCTOR
    Date(const Date &date)
    {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }

    // OPERATOR
    // Date &operator=(const Date &otherDate)
    // {
    //     if (this != &otherDate)
    //     {
    //         this->day = otherDate.day;
    //         this->month = otherDate.month;
    //         this->year = otherDate.month;
    //     }
    //     return *this;
    // }
    bool operator==(const Date &otherDate)
    {
        return this->day == otherDate.day && this->month == otherDate.month && this->year == otherDate.year;
    }
    bool operator!=(const Date &otherDate)
    {
        return this->day != otherDate.day || this->month == otherDate.month || this->year == otherDate.year;
    }
};

bool validateThroughLib(const string date)
{
    stringstream ss(date);
    tm time{};
    ss >> get_time(&time, "%d/%m/%y");
    if (ss.fail())
    {
        cout << "Failed to parse date and time\n";
        return false;
    }
    return true;
}
bool validateWithStream(const string date)
{
    stringstream ss(date);
    int day, month, year;
    char delimiter;
    ss >> day >> delimiter >> month >> delimiter >> year;
    if ((month == 2) && (day >= 30))
    {
        return false;
    }
    return true;
}
bool validate(const int a, const int b, const int c)
{
    if (a < 0 || b < 0 || c < 0 || a >= 32 || b >= 13)
    {
        return false;
    }
    if (b == 2 && a >= 30)
    {
        return false;
    }
    return true;
}

#endif