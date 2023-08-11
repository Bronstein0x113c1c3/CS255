#ifndef CORPORATION_H
#define CORPORATION_H
#include <string>
#include <iostream>
#include "Human.h"
#include "../DSA/Queue.h"
#include "../DSA/HashMap.h"
#include "Company.h"
#include "../UserLib/Record.h"
class Corporation
{
private:
    std::string name;
    President *president = nullptr;
    std::map<unsigned short, VicePresident *> vice_president;
    std::map<std::string, Company *> company_list;

public:
    // CONSTRUCTORS
    Corporation()
    {
        this->vice_president = std::map<unsigned short, VicePresident *>();
        this->company_list = std::map<std::string, Company *>();
    };
    Corporation(std::string name, President *president, std::map<unsigned short, VicePresident *> vice_president, std::map<std::string, Company *> company);
    ~Corporation()
    {
        delete this->president;
        cout << "deleted president" << endl;
        for (auto iter = this->vice_president.begin(); iter != this->vice_president.end(); ++iter)
        {
            delete iter->second;
        }
        cout << "deleted vice president" << endl;
        for (auto iter = this->company_list.begin(); iter != this->company_list.end(); ++iter)
        {
            delete iter->second;
        }
        cout << "delete company list" << endl;
    };

    // OPERATORS
    friend ostream &operator<<(ostream &os, const Corporation &corporation)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Corporation: " + corporation.name << std::endl;
        os << "President: " + corporation.president->getFirstName() + " " + corporation.president->getLastMidName() << std::endl;
        os << "Vice Presidents: ";
        for (auto current = corporation.vice_president.begin(); current != corporation.vice_president.end(); ++current)
        {
            VicePresident *vice_president = (*current).second;
            os << *vice_president << ", ";
        }
        os << std::endl;

        os << "Companies: ";
        for (auto current = corporation.company_list.begin(); current != corporation.company_list.end(); ++current)
        {
            os << *(current->second) << ", ";
        }
        os << std::endl;
        os << "-----------------------------------------------------------" << std::endl;

        return os;
    }
    friend ostream &operator<<(ostream &os, const Corporation *corporation)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Corporation: " + corporation->name << std::endl;
        if (corporation->president != nullptr)
        {
            os << "President: " + corporation->president->getFirstName() + " " + corporation->president->getLastMidName() << std::endl;
            os << "ID: " + corporation->president->getID() << std::endl;
            if (corporation->president->getDateOfBirth() != nullptr)
            {
                os << "Date of birth: " << corporation->president->getDateOfBirth() << "\n";
            }
            else
                os << "Date of birth: " << std::endl;

            os << "Birth place: " << corporation->president->getBirthPlace() << "\n";
            os << "Email: " << corporation->president->getEmail() << "\n";
            os << "Phone number: " << corporation->president->getPhoneNum() << "\n";

            if (corporation->president->getFirstDayAtWork() != nullptr)
            {
                os << "First day at work: " << corporation->president->getFirstDayAtWork() << "\n";
            }
            else
                os << "First day at work: " << std::endl;

            os << "Days Worked: " << std::endl;
            for (auto current = corporation->president->getDaysWork()->begin(); current != corporation->president->getDaysWork()->end(); ++current)
            {
                Record *record = (*current).getValue();
                if (record != nullptr)
                {
                    os << record << std::endl;
                }
            }
        }
        else
            os << "President: " << std::endl;

        os << "Vice Presidents: ";
        for (auto current = corporation->vice_president.begin(); current != corporation->vice_president.end(); ++current)
        {
            if (current->second != nullptr)
            {
                os << current->second << ", ";
            }
        }
        os << std::endl;

        os << "Companies: ";
        for (auto current = corporation->company_list.begin(); current != corporation->company_list.end(); ++current)
        {
            if (current->second != nullptr)
            {
                os << current->second << ", ";
            }
        }
        os << std::endl;
        os << "-----------------------------------------------------------" << std::endl;

        return os;
    }
    bool operator==(const Corporation &otherCorporation)
    {
        return this->name == otherCorporation.name;
    }
    bool operator!=(const Corporation &otherCorporation)
    {
        return this->name != otherCorporation.name;
    }
    // PROPERTIES
    std::string getName() const { return this->name; };
    President *getPresident()
    {
        return this->president;
    };
    std::map<unsigned short, VicePresident *> *getVicePresidentList() { return &(this->vice_president); };
    std::map<std::string, Company *> *getCompanyList()
    {
        return &(this->company_list);
    };
    std::map<unsigned short, VicePresident *> *getPointerofVicePresidentList()
    {
        return &(this->vice_president);
    };
    std::map<std::string, Company *> *getPointerofCompanyList()
    {
        return &(this->company_list);
    };
    void setName(std::string name) { this->name = name; };
    void setPresident(President *president)
    {
        this->president = president;
    };
    void setVicePresidentList(std::map<unsigned short, VicePresident *> vice_president_list)
    {
        this->vice_president = vice_president_list;
    };
    void setCompanyList(std::map<std::string, Company *> company_list)
    {
        this->company_list = company_list;
    };

    // METHODS
    void addVicePresident(VicePresident *vice_president) { this->vice_president.insert({vice_president->getID(), vice_president}); };
    void addCompany(Company *company)
    {
        this->company_list.insert({company->getName(), company});
    };
};

Corporation::Corporation(std::string name, President *president, std::map<unsigned short, VicePresident *> vice_president, std::map<std::string, Company *> company)
{
    this->name = name;

    // delete this->president; //! PREVENT MEMORY LEAK
    this->president = president;

    //! PREVENT MEMORY LEAK
    // delete this->vice_president;
    this->vice_president = vice_president;

    //! PREVENT MEMORY LEAK
    // delete this->company_list;
    this->company_list = company_list;
}

#endif
