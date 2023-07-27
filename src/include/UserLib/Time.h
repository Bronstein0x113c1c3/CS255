#include <chrono>
#include <iostream>

class Time
{
private:
    // Attributes
    std::chrono::hours hours{0};
    std::chrono::minutes minutes{0};

public:
    // Constructor
    Time(int hours = 0, int minutes = 0) : hours{hours}, minutes{minutes} {};

    // Operators
    friend std::ostream &operator<<(std::ostream &os, const Time &time)
    {
        os << time.hours.count() << ':' << time.minutes.count();
        return os;
    }

    // Time operator-(const Time& anotherTime) const
    // {
    //     return Time(this->hours - anotherTime.hours, this->minutes - anotherTime.minutes);
    // }
};
