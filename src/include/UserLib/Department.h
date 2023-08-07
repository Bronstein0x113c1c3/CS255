#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <map>
#include "Human.h"
#include "../DSA/HashMap.h"
class Department
{
private:
    std::string name = "ITDepartment";
    // Manager: Human
    Manager *manager = nullptr;
    // Employee: Human
    std::map<unsigned short, Employee *> *employee_list = new std::map<unsigned short, Employee *>();
    Queue<DeputyManager *> *deputy_manager_list = new Queue<DeputyManager *>();

public:
    Department();
    ~Department();
    Department(std::string name, Manager *manager, Queue<DeputyManager *> *deputy_manager_list, std::map<unsigned short, Employee *> *employee_list);

    // PROPERTIES
    unsigned short getMemberNums() const
    {
        return 1 + this->deputy_manager_list->getSize() + this->employee_list->size();
    };
    Queue<DeputyManager *> *getDeputyManagerList() { return this->deputy_manager_list; };
    std::map<unsigned short, Employee *> *getEmployeeList()
    {
        return this->employee_list;
    };
    Manager *getManager()
    {
        return this->manager;
    };
    std::string getName() const { return this->name; };

    // SETTERS
    void setName(std::string name) { this->name = name; };
    void setDeputyManagerList(Queue<DeputyManager *> *deputy_manager_list)
    {
        //! PREVENT MEMORY LEAK
        this->deputy_manager_list->Clear();
        delete this->deputy_manager_list;

        this->deputy_manager_list = deputy_manager_list;
    };
    void setManager(Manager *manager)
    {
        delete this->manager; //! PREVENT MEMORY LEAK
        this->manager = manager;
    };
    void setEmployeeList(std::map<unsigned short, Employee *> *employee_list)
    {
        //! PREVENT MEMORY LEAK
        delete this->employee_list;
        this->employee_list = employee_list;
    };

    // For stream....
    friend std::ostream &operator<<(std::ostream &os, const Department &department)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Department: " + department.name << std::endl;
        os << "Manager: " + department.manager->getFirstName() + " " + department.manager->getLastMidName() << std::endl;
        os << "Deputy Managers: ";
        for (auto current = department.deputy_manager_list->begin(); current != department.deputy_manager_list->end(); ++current)
        {
            DeputyManager *deputy_manager = (*current).getValue();
            os << *deputy_manager << ", ";
        }
        os << std::endl;

        os << "Employees: ";
        for (auto current = department.employee_list->begin(); current != department.employee_list->end(); ++current)
        {
            os << current->first << ": " << *(current->second) << ", ";
        }
        os << std::endl;
        os << "-----------------------------------------------------------" << std::endl;

        return os;
    };

    friend std::ostream &operator<<(std::ostream &os, const Department *department)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Department: " + department->name << std::endl;
        if (department->manager != nullptr)
        {
            os << "Manager: " + department->manager->getFirstName() + " " + department->manager->getLastMidName() << std::endl;
            os << "ID" + department->manager->getID() << std::endl;
            if (department->manager->getDateOfBirth() != nullptr)
            {
                os << "Date of birth: " << department->manager->getDateOfBirth() << "\n";
            }
            else
                os << "Date of birth: " << std::endl;
            
            os << "Birth place: " << department->manager->getBirthPlace() << "\n";
            os << "Email: " << department->manager->getEmail() << "\n";
            os << "Phone number: " << department->manager->getPhoneNum() << "\n";

            if (department->manager->getFirstDayAtWork() != nullptr)
            {
                os << "First day at work: " << department->manager->getFirstDayAtWork() << "\n";
            }
            else
                os << "First day at work: " << std::endl;
            
            os << "Days Worked: " << std::endl;
            for (auto current = department->manager->getDaysWork()->begin(); current != department->manager->getDaysWork()->end(); ++current)
            {
                Record *record = (*current).getValue();
                if (record != nullptr)
                {
                    os << record << std::endl;
                }
            }
        }
        else
            os << "Manager: ";

        os << "Deputy Managers: ";
        for (auto current = department->deputy_manager_list->begin(); current != department->deputy_manager_list->end(); ++current)
        {
            DeputyManager *deputy_manager = (*current).getValue();
            if (deputy_manager != nullptr)
            {
                os << *deputy_manager << ", ";
            }
        }
        os << std::endl;

        os << "Employees: ";
        for (auto current = department->employee_list->begin(); current != department->employee_list->end(); ++current)
        {
            if (current->second != nullptr)
            {
                os << current->first << ": " << current->second << ", ";
            }
        }
        os << std::endl;
        os << "-----------------------------------------------------------" << std::endl;

        return os;
    };

    bool operator==(const Department &otherDepartment)
    {
        return this->name == otherDepartment.name;
    }
    bool operator!=(const Department &otherDepartment)
    {
        return this->name != otherDepartment.name;
    }
    // Add some stuffs
    void addEmployee(Employee *employee)
    {
        this->employee_list->insert({employee->getID(), employee});
    };
    // DeputyManager: Human
    void addDeputyManager(DeputyManager *deputy_manager)
    {
        this->deputy_manager_list->Enqueue(deputy_manager);
    };
};

Department::Department()
{
}

Department::Department(std::string name, Manager *manager, Queue<DeputyManager *> *deputy_manager_list, std::map<unsigned short, Employee *> *employee_list)
{
    this->name = name;

    //! PREVENT MEMORY LEAK
    delete this->manager;
    this->manager = manager;

    //! PREVENT MEMORY LEAK
    this->deputy_manager_list->Clear();
    delete this->deputy_manager_list;
    this->deputy_manager_list = deputy_manager_list;

    //! PREVENT MEMORY LEAK
    delete this->employee_list;
    this->employee_list = employee_list;
};

Department::~Department()
{
}

#endif