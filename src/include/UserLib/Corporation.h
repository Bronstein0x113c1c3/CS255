#ifndef CORPORATION_H
#define CORPORATION_H
#include <string>
#include <iostream>
#include "Human.h"
#include "../DSA/Queue.h"
#include "../DSA/HashMap.h"
#include "Company.h"
class Corporation
{
private:
    std::string name;
    President *president = nullptr;
    Queue<VicePresident *>* vice_president = new Queue<VicePresident *>();
    std::map<std::string, Company *>* company_list = new std::map<std::string, Company *>();

public:
    // CONSTRUCTORS
    Corporation(){};
    Corporation(std::string name, President *president, Queue<VicePresident *>* vice_president, std::map<std::string, Company *>* company);
    ~Corporation();

    // OPERATORS
    friend ostream &operator<<(ostream &os, const Corporation &corporation)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Corporation: " + corporation.name << std::endl;
        os << "President: " + corporation.president->getFirstName() + " " + corporation.president->getLastMidName() << std::endl;
        os << "Vice Presidents: ";
        for (auto current = corporation.vice_president->begin(); current != corporation.vice_president->end(); ++current)
        {
            VicePresident *vice_president = (*current).getValue();
            os << *vice_president << ", ";
        }
        os << std::endl;

        os << "Companies: ";
        for (auto current = corporation.company_list->begin(); current != corporation.company_list->end(); ++current)
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
        for (auto current = corporation->vice_president->begin(); current != corporation->vice_president->end(); ++current)
        {
            VicePresident *vice_president = (*current).getValue();
            if (vice_president != nullptr)
            {
                os << *vice_president << ", ";
            }
        }
        os << std::endl;

        os << "Companies: ";
        for (auto current = corporation->company_list->begin(); current != corporation->company_list->end(); ++current)
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
    Queue<VicePresident *>* getVicePresidentList() { return this->vice_president; };
    std::map<std::string, Company *>* getCompanyList()
    {
        return this->company_list;
    };
    Queue<VicePresident *> *getPointerofVicePresidentList()
    {
        return this->vice_president;
    };
    std::map<std::string, Company *> *getPointerofCompanyList()
    {
        return this->company_list;
    };
    void setName(std::string name) { this->name = name; };
    void setPresident(President *president) 
    { 
        delete this->president;     //! PREVENT MEMORY LEAK
        this->president = president; 
    };
    void setVicePresidentList(Queue<VicePresident *>* vice_president_list) 
    { 
        //! PREVENT MEMORY LEAK
        this->vice_president->Clear();
        delete this->vice_president;

        this->vice_president = vice_president_list; 
    };
    void setCompanyList(std::map<std::string, Company *>* company_list)
    {
        delete this->company_list;  //! PREVENT MEMORY LEAK
        this->company_list = company_list;
    };

    // METHODS
    void addVicePresident(VicePresident *vice_president) { this->vice_president->Enqueue(vice_president); };
    void addCompany(Company *company)
    {
        this->company_list->insert({company->getName(), company});
    };
};

Corporation::Corporation(std::string name, President *president, Queue<VicePresident *>* vice_president, std::map<std::string, Company *>* company)
{
    this->name = name;

    delete this->president;     //! PREVENT MEMORY LEAK
    this->president = president;

    //! PREVENT MEMORY LEAK
    this->vice_president->Clear();
    delete this->vice_president;
    this->vice_president = vice_president;

    //! PREVENT MEMORY LEAK
    delete this->company_list;
    this->company_list = company_list;
}

Corporation::~Corporation()
{
}

#endif
