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
    Manager *manager;
    // Employee: Human
    std::map<unsigned short, Employee *> employee_list = std::map<unsigned short, Employee *>();
    Queue<DeputyManager *> deputy_manager_list = Queue<DeputyManager *>();

public:
    Department();
    ~Department();
    Department(std::string name, Manager *manager, const std::map<unsigned short, Employee *> employee_list, const Queue<DeputyManager *> deputy_manager_list);

    // PROPERTIES
    unsigned short getMemberNums() const
    {
        return 1 + this->deputy_manager_list.getSize() + this->employee_list.size();
    };
    Queue<DeputyManager *> getDeputyManagerList() { return this->deputy_manager_list; };
    std::map<unsigned short, Employee *> getEmployeeList()
    {
        return this->employee_list;
    };
    Manager getManager() const { return *(this->manager); };
    std::string getName() const { return this->name; };

    std::map<unsigned short, Employee *> *getPointerOfEmployeeList()
    {
        return &(this->employee_list);
    }
    Queue<DeputyManager *> *getPointerOfDeputyManagerList()
    {
        return &(this->deputy_manager_list);
    };
    // SETTERS
    void setName(std::string name) { this->name = name; };
    void setDeputyManagerList(const Queue<DeputyManager *> deputy_manager_list) { this->deputy_manager_list = deputy_manager_list; };
    void setManager(Manager *manager) { this->manager = manager; };
    void setEmployeeList(const std::map<unsigned short, Employee *> employee_list)
    {
        this->employee_list = employee_list;
    };

    // For stream....
    friend std::ostream &operator<<(std::ostream &os, const Department &department)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Department: " + department.name << std::endl;
        os << "Manager: " + department.manager->getFirstName() + " " + department.manager->getLastMidName() << std::endl;
        os << "Deputy Managers: ";
        for (auto current = department.deputy_manager_list.begin(); current != department.deputy_manager_list.end(); ++current)
        {
            DeputyManager *deputy_manager = (*current).getValue();
            os << *deputy_manager << ", ";
        }
        os << std::endl;

        os << "Employees: ";
        for (auto current = department.employee_list.begin(); current != department.employee_list.end(); ++current)
        {
            os << current->first << ": " << *(current->second) << ", ";
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
        this->employee_list[employee->getID()] = employee;
    };
    // DeputyManager: Human
    void addDeputyManager(DeputyManager *deputy_manager)
    {
        this->deputy_manager_list.Enqueue(deputy_manager);
    };
};

Department::Department()
{
}

Department::Department(std::string name, Manager *manager, const std::map<unsigned short, Employee *> employee_list, const Queue<DeputyManager *> deputy_manager_list)
{
    this->name = name;
    this->manager = manager;
    this->employee_list = employee_list;
    this->deputy_manager_list = deputy_manager_list;
};

Department::~Department()
{
}

#endif