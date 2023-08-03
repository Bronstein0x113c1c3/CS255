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
    Manager manager = Manager();
    // Employee: Human
    std::map<int, Employee> employee_list;
    Queue<DeputyManager> deputy_manager_list;

public:
    Department();
    ~Department();
    Department(std::string name, Manager manager, const std::map<int, Employee> &employee_list, const Queue<DeputyManager> &deputy_manager_list);

    // PROPERTIES
    int getMemberNums() const
    {
        return 1 + this->deputy_manager_list.getSize() + this->employee_list.size();
    };
    Queue<DeputyManager> getDeputyManagerList() const { return this->deputy_manager_list; };
    std::map<int, Employee> getEmployeeList() const
    {
        return this->employee_list;
    };
    Manager getManager() const { return this->manager; };
    std::string getName() const { return this->name; };

    // SETTERS
    void setName(std::string name) const { this->name = name; };
    void setDeputyManagerList(const Queue<DeputyManager> &deputy_manager_list) { this->deputy_manager_list = deputy_manager_list; };
    void setManager(Manager manager) { this->manager = manager; };
    void setEmployeeList(const std::map<int, Employee> &employee_list) 
    { 
        this->employee_list = employee_list; 
    };

    // For stream....
    friend std::ostream &operator<<(std::ostream &os, const Department &department)
    {
        os << department.name << std::endl
           << department.manager << std::endl
           << department.deputy_manager_list << endl;

        for (auto current = department.employee_list.begin(); current != department.employee_list.end(); ++current)
        {
            std::cout << current->first << ": " << std::endl;
        }

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
    void addEmployee(Employee employee)
    {
        this->employee_list[employee.getID()] = employee;
    };
    // DeputyManager: Human
    void addDeputyManager(DeputyManager deputy_manager)
    {
        this->deputy_manager_list.Enqueue(deputy_manager);
    };
};

Department::Department()
{
}

Department::Department(std::string name, Manager manager, const std::map<int, Employee> &employee_list, const Queue<DeputyManager> &deputy_manager_list)
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