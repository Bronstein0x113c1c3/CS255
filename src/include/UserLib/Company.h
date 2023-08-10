#ifndef COMPANY_H
#define COMPANY_H
using namespace std;
#include "./Department.h"
#include "Record.h"

class Company
{
private:
    std::string name;
    // Director: Human
    Director *director = nullptr;
    // ViceDirector: Human
    std::map<unsigned short, ViceDirector *> vice_director;
    std::map<std::string, Department *> department_list;

public:
    Company()
    {
        this->vice_director = std::map<unsigned short, ViceDirector *>();
        this->department_list = std::map<std::string, Department *>();
    };
    Company(std::string name)
    {
        this->name = name;
    }
    Company(std::string name, Director *director, std::map<unsigned short, ViceDirector *> vice_director, std::map<std::string, Department *> department_list)
    {
        this->name = name;

        this->director = director;

        this->vice_director = vice_director;

        this->department_list = department_list;
    }
    ~Company()
    {
        // CLEAN UP MEMORY SPACE
        delete this->director;
        cout << "deleted director" << endl;
        // CLEAN UP MEMORY FOR VICE DIRECTORS
        for (auto iter = this->vice_director.begin(); iter != this->vice_director.end(); ++iter)
        {
            delete iter->second;
        }
        cout << "deleted vice director" << endl;
        for (auto iter = this->department_list.begin(); iter != this->department_list.end(); ++iter)
        {
            delete iter->second;
        }
        cout << "deleted department" << endl;
    };

    std::string getName() const { return this->name; };
    Director *getDirector()
    {
        return this->director;
    };
    std::map<unsigned short, ViceDirector *> *getViceDirectorList()
    {
        return &(this->vice_director);
    };
    std::map<std::string, Department *> *getDepartmentList()
    {
        return &(this->department_list);
    };
    std::map<std::string, Department *> *getPointerOfDepartmentList()
    {
        return &(this->department_list);
    };
    std::map<unsigned short, ViceDirector *> *getPointerOfViceDirector()
    {
        return &(this->vice_director);
    };
    void setViceDirectorList(std::map<unsigned short, ViceDirector *> vice_director_list)
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
        this->department_list.insert({department->getName(), department});
    };
    void addViceDirector(ViceDirector *vice_director)
    {
        this->vice_director.insert({vice_director->getID(), vice_director});
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
            os << current->second << ", ";
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
    friend std::ostream &operator<<(std::ostream &os, const Company *company)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Company: " + company->name << std::endl;
        if (company->director != nullptr)
        {
            os << "Director: " + company->director->getFirstName() + " " + company->director->getLastMidName() << endl;
            os << "ID" + company->director->getID() << std::endl;
            if (company->director->getDateOfBirth() != nullptr)
            {
                os << "Date of birth: " << company->director->getDateOfBirth() << "\n";
            }
            else
                os << "Date of birth: " << std::endl;

            os << "Birth place: " << company->director->getBirthPlace() << "\n";
            os << "Email: " << company->director->getEmail() << "\n";
            os << "Phone number: " << company->director->getPhoneNum() << "\n";

            if (company->director->getFirstDayAtWork() != nullptr)
            {
                os << "First day at work: " << company->director->getFirstDayAtWork() << "\n";
            }
            else
                os << "First day at work: " << std::endl;

            os << "Days Worked: " << std::endl;
            for (auto current = company->director->getDaysWork()->begin(); current != company->director->getDaysWork()->end(); ++current)
            {
                Record *record = (*current).getValue();
                if (record != nullptr)
                {
                    os << record << std::endl;
                }
            }
        }
        else
            os << "Director: ";

        os << "Vice Directors: ";
        std::cout << company->vice_director.size();
        for (auto current = company->vice_director.begin(); current != company->vice_director.end(); ++current)
        {
            if (current->second != nullptr)
            {
                os << current->second << ", ";
            }
        }
        os << std::endl;

        os << "Departments: ";
        for (auto current = company->department_list.begin(); current != company->department_list.end(); ++current)
        {
            if (current->second != nullptr)
            {
                os << current->first << ": " << current->second << ", ";
            }
        }
        os << std::endl;
        os << "-----------------------------------------------------------" << std::endl;
        return os;
    }
    bool operator==(const Company &otherCompany)
    {
        return this->name == otherCompany.name;
    }
    bool operator!=(const Company &otherCompany)
    {
        return this->name != otherCompany.name;
    }
};

#endif