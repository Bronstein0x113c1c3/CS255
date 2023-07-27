#include <bits/stdc++.h>

using namespace std;
bool validation_through_lib(string date);
bool validation_with_stream(string date);
bool validation(int a, int b, int c);
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 0, int month = 0, int year = 9999)
    {
        if (validation(day, month, year))
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }
        else
        {
            this->day = 0;
            this->month = 0;
            this->year = 9999;
        }
    }

    Date(string date)
    {
        int day = 0, month = 0, year = 9999;
        if (validation_through_lib(date) && validation_with_stream(date))
        {
            stringstream ss(date);
            char delimiter;
            ss >> day >> delimiter >> month >> delimiter >> year;
            this->day = day;
            this->month = month;
            this->year = year;
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
};
Date parsing(string date)
{
    int day = 0, month = 0, year = 9999;
    if (validation_through_lib(date) && validation_with_stream(date))
    {
        stringstream ss(date);
        char delimiter;
        ss >> day >> delimiter >> month >> delimiter >> year;
        return Date(day, month, year);
    }
    return Date(day, month, year);
}
bool validation_through_lib(string date)
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
bool validation_with_stream(string date)
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
bool validation(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0 || a >= 32 || b >= 13)
    {
        return false;
    }
    if (b == 2 || a >= 30)
    {
        return false;
    }
    return true;
}