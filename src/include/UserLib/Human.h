#include <string>
#include "../DSA/Queue.h"
#include "Department.h"
#include "Date.h"
#include "Record.h"

class Human
{
private:
    int ID;
    std::string last_mid_name;
    std::string first_name;
    Department department;
    std::string position;
    Date date_of_birth;
    std::string birth_place;
    std::string email;
    std::string phone_num;
    Date first_day_at_work;
    Queue<Record> days_work = Queue<Record>();
public:
    Human(/* args */);
    ~Human();
};

Human::Human(/* args */)
{
}

Human::~Human()
{
}
