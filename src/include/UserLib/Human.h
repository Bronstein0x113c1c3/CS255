#include <string>
#include "../DSA/Queue.h"
#include "Department.h"
#include "Date.h"
#include "Record.h"

using namespace std;
class Human
{
private:
    int ID;
    std::string last_mid_name;
    std::string first_name;
    string department;
    std::string position;
    Date date_of_birth;
    std::string birth_place;
    std::string email;
    std::string phone_num;
    Date first_day_at_work;
    Queue<Record> days_work;

public:
    Human(int ID, string last_mid_name, string first_name, string department, string position, string dob, string birth_place, string email, string phone_num, string first_day_at_work);
    friend std::ostream &operator<<(std::ostream &os, const Human &human)
    {
        os << human.ID << "\n";
        os << human.last_mid_name << "\n";
        os << human.first_name << "\n";
        os << human.department << "\n";
        os << human.position << "\n";
        os << human.date_of_birth << "\n";
        os << human.birth_place << "\n";
        os << human.email << "\n";
        os << human.phone_num << "\n";
        os << human.first_day_at_work << "\n";
        os << human.days_work << "\n";
        return os;
    };
    ~Human();
};

Human::Human(int ID, string last_mid_name, string first_name, string department, string position, string dob, string birth_place, string email, string phone_num, string first_day_at_work)
{
    this->ID = ID;
    this->last_mid_name = last_mid_name;
    this->first_name = first_name;
    this->department = department;
    this->position = position;
    this->date_of_birth = Date(dob);
    this->birth_place = birth_place;
    this->email = email;
    this->phone_num = phone_num;
    this->first_day_at_work = Date(first_day_at_work);
}


Human::~Human()
{
}
