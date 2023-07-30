#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "../DSA/Queue.h"

#include "Date.h"
#include "Record.h"

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
    Human() : date_of_birth{Date()}, first_day_at_work{Date()}, days_work{Queue<Record>()} {};
    Human(int ID, std::string last_mid_name, std::string first_name, std::string department, std::string position, std::string dob, std::string birth_place, std::string email, std::string phone_num, std::string first_day_at_work);
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
    void addRecord(const Queue<Record> &record);

    // PROPERTIES
    int getID() const { return this->ID; };
    std::string getLastMidName() const { return this->last_mid_name; };
    std::string getFirstName() const { return this->first_name; };
    std::string getDepartment() const { return this->department; };
    std::string getPosition() const { return this->position; };
    Date getDateOfBirth() const { return this->date_of_birth; };
    std::string getBirthPlace() const { return this->birth_place; };
    std::string getEmail() const { return this->email; };
    std::string getPhoneNum() const { return this->phone_num; };
    Date getFirstDayAtWork() const { return this->first_day_at_work; };

    void setLastMidName(const std::string last_mid_name) { this->last_mid_name = last_mid_name; };
    void setFirstName(const std::string first_name) { this->first_name = first_name; };
    void setDepartment(const std::string department) { this->department = department; };
    void setPosition(const std::string position) { this->position = position; };
    void setDateOfBirth(const Date &date_of_birth) { this->date_of_birth = date_of_birth; };
    void setBirthPlace(const std::string birth_place) { this->birth_place = birth_place; };
    void setEmail(const std::string email) { this->email = email; };
    void setPhoneNum(const std::string phone_num) { this->phone_num = phone_num; };
    void setFirstDayAtWork(const Date &first_day_at_work) { this->first_day_at_work = first_day_at_work; };
    Queue<Record> getDaysWork() const { return this->days_work; };

    // METHODS
    void addDaysWork(const Record new_record)
    {
        this->days_work.Enqueue(new_record);
    }
};

Human::Human(int ID, std::string last_mid_name, std::string first_name, std::string department, std::string position, std::string dob, std::string birth_place, std::string email, std::string phone_num, std::string first_day_at_work)
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
void Human::addRecord(const Queue<Record> &record)
{
    this->days_work = record;
}
Human::~Human()
{
}

class Employee : public Human
{
};
class DeputyManager : public Human
{
};
class Manager : public Human
{
};
class ViceDirector : public Human
{
};
class Director : public Human
{
};
class VicePresident : public Human
{
};
class President : public Human
{
};

#endif