#ifndef TIME_H
#define TIME_H

#include <chrono>
#include <iostream>
#include <sstream>

class Time
{
private:
    // Attributes
    std::chrono::hours hours{0};
    std::chrono::minutes minutes{0};

public:
    // Constructor
    Time(int hours = 0, int minutes = 0);
    Time(std::chrono::hours hours, std::chrono::minutes minutes);
    Time(std::string time_str); // If the User type "20:10"
    Time(const Time& anotherTime);  // Copy CONSTRUCTOR

    // Properties
    int getHours() const;
    int getMinutes() const;

    // Operators
    friend std::ostream &operator<<(std::ostream &os, const Time &time)
    {
        os << time.hours.count() << ':' << time.minutes.count();
        return os;
    }

    Time operator-(const Time &anotherTime) const;
    Time operator+(const Time &anotherTime) const;
    Time& operator=(const Time &anotherTime);
};
// COPY CONSTRUCTOR
Time::Time(const Time& anotherTime)
{
    this->hours = anotherTime.hours;
    this->minutes = anotherTime.minutes;
}


// Constructors
Time::Time(int hours, int minutes)
{
    //* To Prevent Exceeding Limit Hour
    if (hours < 0)
    {
        this->hours = std::chrono::hours{0};
        this->minutes = std::chrono::minutes{0};
        return;
    }
    else if (hours > 24 && minutes > 0)
    {
        this->hours = std::chrono::hours{24};
        this->minutes = std::chrono::minutes{0};
        return;
    }

    //* To Prevent Exceeding Limit Minute
    if (minutes >= 60)
    {
        int hoursToAdd = 0;
        int spareMinute = minutes;
        while (spareMinute >= 60)
        {
            spareMinute -= 60;
            hoursToAdd++;
        }

        if (hours + hoursToAdd < 24)
        {
            //* Make the new Time
            std::chrono::hours newTime{hours + hoursToAdd};
            this->hours = newTime;
            this->minutes = std::chrono::minutes{spareMinute};
            return;
        }
        else
        {
            //* If the Spare Time is too large
            this->hours = std::chrono::hours{24};
            this->minutes = std::chrono::minutes{0};
            return;
        }
    }

    // If none one those Edge Case Appear
    this->hours = std::chrono::hours{hours};
    this->minutes = std::chrono::minutes{minutes};
}

// From chrono to Time
Time::Time(std::chrono::hours hours, std::chrono::minutes minutes)
{
    // Translate hours to int
    int hours_int = hours.count();
    int minutes_int = minutes.count();

    //* To Prevent Exceeding Limit Hour
    if (hours_int < 0)
    {
        this->hours = std::chrono::hours{0};
        this->minutes = std::chrono::minutes{0};
        return;
    }
    else if (hours_int > 24 && minutes_int > 0)
    {
        this->hours = std::chrono::hours{24};
        this->minutes = std::chrono::minutes{0};
        return;
    }

    //* To Prevent Exceeding Limit Minute
    if (minutes_int >= 60)
    {
        int hoursToAdd = 0;
        int spareMinute = minutes_int;
        while (spareMinute >= 60)
        {
            spareMinute -= 60;
            hoursToAdd++;
        }

        if (hours_int + hoursToAdd < 24)
        {
            //* Make the new Time
            std::chrono::hours newTime{hours_int + hoursToAdd};
            this->hours = newTime;
            this->minutes = std::chrono::minutes{spareMinute};
            return;
        }
        else
        {
            //* If the Spare Time is too large
            this->hours = std::chrono::hours{24};
            this->minutes = std::chrono::minutes{0};
            return;
        }
    }

    // If none one those Edge Case Appear
    this->hours = hours;
    this->minutes = minutes;
}

// From string to Time
Time::Time(std::string time_str)
{
    std::stringstream ss(time_str);

    char delimeter;
    int hours;
    int minutes;

    //? Extract String Type to all different part
    ss >> hours >> delimeter >> minutes;

    //* To Prevent Exceeding Limit Hour
    if (hours < 0)
    {
        this->hours = std::chrono::hours{0};
        this->minutes = std::chrono::minutes{0};
        return;
    }
    else if (hours > 24 && minutes > 0)
    {
        this->hours = std::chrono::hours{24};
        this->minutes = std::chrono::minutes{0};
        return;
    }

    //* To Prevent Exceeding Limit Minute
    if (minutes >= 60)
    {
        int hoursToAdd = 0;
        int spareMinute = minutes;
        while (spareMinute >= 60)
        {
            spareMinute -= 60;
            hoursToAdd++;
        }

        if (hours + hoursToAdd < 24)
        {
            //* Make the new Time
            std::chrono::hours newTime{hours + hoursToAdd};
            this->hours = newTime;
            this->minutes = std::chrono::minutes{spareMinute};
            return;
        }
        else
        {
            //* If the Spare Time is too large
            this->hours = std::chrono::hours{24};
            this->minutes = std::chrono::minutes{0};
            return;
        }
    }

    // If none one those Edge Case Appear
    this->hours = std::chrono::hours{hours};
    this->minutes = std::chrono::minutes{minutes};
}

// Properties
int Time::getHours() const
{
    return this->hours.count();
}

int Time::getMinutes() const
{
    return this->hours.count();
}

// Operators
Time Time::operator-(const Time &anotherTime) const
{
    // Calculating the number of hours short of employees
    // arrive late or leave early. Round up to 1 hour
    int minutesShortage = this->minutes.count() - anotherTime.minutes.count();
    int hoursShortage = this->hours.count() - anotherTime.hours.count();

    if (minutesShortage != 0)
    {
        if (hoursShortage < 1)
        {
            // To Prevent the Hour is 0
            hoursShortage = 1;
        }

        return Time(hoursShortage, 0);
    }

    return Time(hoursShortage, minutesShortage);
}

Time Time::operator+(const Time &anotherTime) const
{
    return Time(this->hours.count() + anotherTime.hours.count(), this->minutes.count() + anotherTime.minutes.count());
}

Time& Time::operator=(const Time& anotherTime) 
{
    if (this != &anotherTime)
    {
        this->hours = anotherTime.hours;
        this->minutes = anotherTime.minutes;
    }
    return *this;
} 

#endif