#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Human.h"
#include "../DSA/HashMap.h"
class Department
{
private:
    std::string name;
    // Manager: Human
    Manager manager;
    // Employee: Human
    HashMap<int, Employee> employee_list;
    Queue<DeputyManager> deputy_manager_list;

public:
    Department();
    ~Department();
    Department(std::string name, Manager manager, HashMap<int, Employee> employee_list, Queue<DeputyManager> deputy_manager_list);
    
    //PROPERTIES
    int getMemberNums() { return 1 + this->deputy_manager_list.getSize() + this->employee_list.getAmountValueOccupy(); };
    Queue<DeputyManager> getDeputyManagerList() { return this->deputy_manager_list; };
    HashMap<int, Employee> getEmployeeList() { return this->employee_list; };
    Manager getManager() { return this->manager; };
    
    //SETTERS
    void setDeputyManagerList(Queue<DeputyManager> deputy_manager_list) { this->deputy_manager_list = deputy_manager_list; };
    void setManager(Manager manager) { this->manager = manager; };
    void setEmployeeList(HashMap<int, Employee> employee_list) { this->employee_list = employee_list; };
    
    //For stream....
    friend std::ostream &operator<<(std::ostream &os, const Department& department){
        os<<department.name<<std::endl<<department.manager<<std::endl<<department.employee_list<<std::endl<<department.deputy_manager_list<<endl;
        return os;
    };
    //Add some stuffs
    //Employee: Human
    void addEmployee(Employee employee){
        this->employee_list.assign(employee.getID(),employee);
    };
    //DeputyManager: Human
    void addDeputyManager(DeputyManager deputy_manager){
        this->deputy_manager_list.Enqueue(deputy_manager);
    };
};

Department::Department()
{
    
}

Department::Department(std::string name, Manager manager, HashMap<int, Employee> employee_list, Queue<DeputyManager> deputy_manager_list)
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