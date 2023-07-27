#include "./Time.h"
#include "./Date.h"
#include <sstream>
using namespace std;
class Record
{
private:
    Date day_worked;
    Time time_start_work;
    Time time_go_home;

public:
    Record(Date day_worked, Time time_start_work, Time time_go_home)
    {
        this->day_worked = day_worked;
        this->time_start_work = time_start_work;
        this->time_start_work = time_go_home;
    }
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
        this->day_worked = Date(day_worked);
        this->time_start_work = Time(time_start_work);
        this->time_start_work = Time(time_go_home);
        return;
    }
    friend std::ostream &operator<<(std::ostream &os, const Record &record)
    {
        os << record.day_worked << "," << record.time_start_work << "/" << record.time_go_home;
        return os;
    }
    Time calculateTimeShortage()
    {
        return this->time_go_home - this->time_start_work;
    }
};
