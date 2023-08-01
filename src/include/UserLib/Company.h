#ifndef COMPANY_H
#define COMPANY_H
using namespace std;
#include "./Department.h"

class Company
{
private:
    std::string name;
    // Director: Human
    Director director;
    // ViceDirector: Human
    Queue<ViceDirector> vice_director;
    Queue<Department> department_list;

public:
    Company(){};
    Company(std::string name, Director director, Queue<ViceDirector> vice_director, Queue<Department> department_list)
    {
        this->name = name;
        this->director = director;
        this->vice_director = vice_director;
        this->department_list = department_list;
    }
    ~Company() {};
    std::string getName() { return this->name; };
    Director getDirector() { return this->director; };
    Queue<ViceDirector> getViceDirectorList() { return this->vice_director; };
    Queue<Department> getDepartmentList() { return this->department_list; };

    void setViceDirectorList(Queue<ViceDirector> vice_director_list)
    {
        this->vice_director = vice_director_list;
    };
    void setName(std::string name)
    {
        this->name = name;
    };
    void setDirector(Director director)
    {
        this->director = director;
    };
    void setDepartmentList(Queue<Department> department_list)
    {
        this->department_list = department_list;
    };
    void addDepartment(Department department)
    {
        this->department_list.Enqueue(department);
    };
    void addViceDirector(ViceDirector vice_director)
    {
        this->vice_director.Enqueue(vice_director);
    }
    // OPERATOR
    friend std::ostream &operator<<(std::ostream &os, const Company &company)
    {
        os << company.name << std::endl
           << company.director << endl
           << company.vice_director << endl
           << company.department_list << endl;
        return os;
    }
    bool operator==(const Company &otherCompany)
    {
        this->name == otherCompany.name;
    }
    bool operator!=(const Company &otherCompany)
    {
        return this->name != otherCompany.name;
    }
};

#endif