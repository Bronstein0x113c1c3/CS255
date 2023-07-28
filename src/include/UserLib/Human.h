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
    Human(int ID, string last_mid_name,string first_name, string department, string dob, string birth_place, string email, string phone_num,string first_day_at_work);
    friend ostream &operator<<(ostream os, const Human &human){
        os<<endl<<human.ID<<endl<<human.last_mid_name<<endl<<human.first_name<<endl<<human.department<<endl<<human.position<<endl<<human.date_of_birth<<endl<<human.birth_place<<endl<<human.email<<endl<<human.phone_num<<endl<<human.first_day_at_work;
    };
    ~Human();
};

Human::Human(int ID, string last_mid_name,string first_name, string department, string dob, string birth_place, string email, string phone_num,string first_day_at_work){
    this->ID = ID;
    this->last_mid_name = last_mid_name;
    this->first_name = first_name;
    this->department = department;
    this->date_of_birth = Date(dob);
    this->birth_place = birth_place;
    this->email = email;
    this->phone_num = phone_num;
    this->first_day_at_work = Date(first_day_at_work);
}
ostream &operator<<(ostream os,const Queue<Record> &days_work){
    for (Queue<Record>::Iterator current = days_work.begin(); current != days_work.end(); ++current)
    {
        std::cout << *current << std::endl;
    }
    
}

Human::~Human()
{
}
