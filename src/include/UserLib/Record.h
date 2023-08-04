#ifndef RECORD_H
#define RECORD_H

#include "Time.h"
#include "Date.h"
#include <sstream>
using namespace std;
class Record
{
private:
    Date *day_worked = nullptr;
    Time *time_start_work = nullptr;
    Time *time_go_home = nullptr;

public:
    // CONSTRUCTORS
    Record(){};
    Record(Date *day_worked, Time *time_start_work, Time *time_go_home) : day_worked{day_worked}, time_start_work{time_start_work}, time_go_home{time_go_home} {};

    Record(string record)
    {
        for (char &x : record)
        {
            if (x == ',')
            {
                x = ' ';
            }
        }
        stringstream ss(record);
        string day_worked, time_start_work, time_go_home;
        ss >> day_worked >> time_start_work >> time_go_home;
        this->day_worked = new Date(day_worked);
        this->time_start_work = new Time(time_start_work);
        this->time_start_work = new Time(time_go_home);
        return;
    }

    // COPY CONSTRUCTOR
    Record(const Record *otherRecord)
    {
        if (this != otherRecord)
        {
            this->day_worked = otherRecord->day_worked;
            this->time_start_work = otherRecord->time_start_work;
            this->time_go_home = otherRecord->time_go_home;
        }
    }

    // OPERATORS
    friend std::ostream &operator<<(std::ostream &os, const Record &record)
    {
        os << record.day_worked << "," << record.time_start_work << "," << record.time_go_home;
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const Record *record)
    {
        if (record->day_worked != nullptr)
        {
            os << record->day_worked << ",";
        }

        if (record->time_start_work != nullptr)
        {
            os << record->time_start_work << "; ";
        }

        if (record->time_go_home != nullptr)
        {
            os << record->time_go_home;
        }
        return os;
    }
    Record operator=(const Record *otherRecord)
    {
        if (this != otherRecord)
        {
            this->day_worked = otherRecord->day_worked;
            this->time_start_work = otherRecord->time_start_work;
            this->time_go_home = otherRecord->time_go_home;
        }
        return *this;
    }

    // METHODS
    Time calculateTimeShortage()
    {
        return this->time_go_home - this->time_start_work;
    }

    // PROPERTIES
    Date getDayWorked() const { return *(this->day_worked); };
    Time getTimeStartWork() const { return *(this->time_start_work); };
    Time getTimeGoHome() const { return *(this->time_go_home); };

    void setDayWorked(Date *day_worked) { this->day_worked = day_worked; };
    void setTimeStartWork(Time *time_started) { this->time_start_work = time_started; };
    void setTimeGoHome(Time *time_go_home) { this->time_go_home = time_go_home; };

    // OPERATORS
    bool operator==(const Record &otherRecord)
    {
        return this->day_worked == otherRecord.day_worked && this->time_start_work == otherRecord.time_start_work && this->time_go_home == otherRecord.time_go_home;
    }
    bool operator!=(const Record &otherRecord)
    {
        return this->day_worked != otherRecord.day_worked || this->time_start_work != otherRecord.time_start_work || this->time_go_home != otherRecord.time_go_home;
    }
};

#endif