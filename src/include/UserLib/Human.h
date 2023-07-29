#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "../DSA/Queue.h"

#include "Date.h"
#include "Record.h"

using namespace std;
class Human
{
private:
    int ID;
    std::string last_mid_name;
    std::string first_name;
    std::string department;
    std::string position;
    Date date_of_birth;
    std::string birth_place;
    std::string email;
    std::string phone_num;
    Date first_day_at_work;
    Queue<Record> days_work;

public:
    Human(int ID, string last_mid_name, string first_name, string department, string position, string dob, string birth_place, string email, string phone_num, string first_day_at_work);
    ~Human();
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
    void addRecord(Queue<Record> record);

    //PROPERTIES
    int getID() { return this->ID; };
    string getLastMidName() const { return this->last_mid_name; };
    string getFirstName() const { return this->first_name; };
    string getDepartment() const { return this->department; };
    string getPosition() const { return this->position; };
    Date getDateOfBirth() const { return this->date_of_birth; };
    string getBirthPlace() const { return this->birth_place; };
    string getEmail() const { return this->email; };
    string getPhoneNum() const { return this->phone_num; };
    Date getFirstDayAtWork() const { return this->first_day_at_work; };

    void setLastMidName(string last_mid_name) { this->last_mid_name = last_mid_name; };
    void setFirstName(string first_name) { this->first_name = first_name; };
    void setDepartment(string department) { this->department = department; };
    void setPosition(string position) { this->position = position; };
    void setDateOfBirth(Date date_of_birth) { this->date_of_birth = date_of_birth; };
    void setBirthPlace(string birth_place) { this->birth_place = birth_place; };
    void setEmail(string email) { this->email = email; };
    void setPhoneNum(string phone_num) { this->phone_num = phone_num; };
    void setFirstDayAtWork(Date first_day_at_work) { this->first_day_at_work = first_day_at_work; };
    Queue<Record> getDaysWork() const { return this->days_work; };

    // METHODS
    void addDaysWork(Record new_record) 
    { 
        this->days_work.Enqueue(new_record); 
    }
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
void Human::addRecord(const Queue<Record> record)
{
    this->days_work = record;
}
Human::~Human()
{
}

// class Employee:Human

#endif