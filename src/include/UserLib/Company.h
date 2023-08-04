#ifndef COMPANY_H
#define COMPANY_H
using namespace std;
#include "./Department.h"

class Company
{
private:
    std::string name;
    // Director: Human
    Director* director;
    // ViceDirector: Human
    Queue<ViceDirector *> vice_director;
    std::map<std::string, Department *> department_list;

public:
    Company(){};
    Company(std::string name)
    {
        this->name = name;
    }
    ~Company(){};

    std::string getName() const { return this->name; };
    Director getDirector() const { return *(this->director); };
    Queue<ViceDirector *> &getViceDirectorList() { return this->vice_director; };
    std::map<std::string, Department *> getDepartmentList()
    {
        return this->department_list;
    };
    std::map<std::string, Department *> *getPointerOfDepartmentList()
    {
        return &(this->department_list);
    };
    Queue<ViceDirector *> *getPointerOfViceDirector()
    {
        return &(this->vice_director);
    };
    void setViceDirectorList(Queue<ViceDirector *> vice_director_list)
    {
        this->vice_director = vice_director_list;
    };
    void setName(std::string name)
    {
        this->name = name;
    };
    void setDirector(Director *director)
    {
        this->director = director;
    };
    void setDepartmentList(std::map<std::string, Department *> department_list)
    {
        this->department_list = department_list;
    };
    void addDepartment(Department *department)
    {
        this->department_list[department->getName()] = department;
        // this->department_list.assign(department.getName(),department);
    };
    void addViceDirector(ViceDirector *vice_director)
    {
        this->vice_director.Enqueue(vice_director);
    }
    // OPERATOR
    friend std::ostream &operator<<(std::ostream &os, const Company &company)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Company: " + company.name << std::endl;
        os << "Director: " + company.director->getFirstName() + " " + company.director->getLastMidName() << endl;
        os << "Vice Directors: ";
        for (auto current = company.vice_director.begin(); current != company.vice_director.end(); ++current)
        {
            ViceDirector *vice_director = (*current).getValue();
            os << *vice_director << ", ";
        }
        os << std::endl;

        os << "Departments: ";
        for (auto current = company.department_list.begin(); current != company.department_list.end(); ++current)
        {
            os << current->first << ": " << *(current->second) << ", ";
        }
        os << std::endl;
        os << "-----------------------------------------------------------" << std::endl;
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