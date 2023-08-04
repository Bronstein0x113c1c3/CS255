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
    std::string name = "BKCorporation";
    President president = President();
    Queue<VicePresident *> vice_president = Queue<VicePresident *>();
    std::map<std::string, Company *> company_list;

public:
    // CONSTRUCTORS
    Corporation(){};
    Corporation(std::string name, President president, Queue<VicePresident *> vice_president, std::map<std::string, Company *> company);
    ~Corporation();

    // OPERATORS
    friend ostream &operator<<(ostream &os, const Corporation &corporation)
    {
        os << "-----------------------------------------------------------" << std::endl;
        os << "Corporation: " + corporation.name << std::endl;
        os << "President: " + corporation.president.getFirstName() + " " + corporation.president.getLastMidName() << std::endl;
        os << "Vice Presidents: ";
        for (auto current = corporation.vice_president.begin(); current != corporation.vice_president.end(); ++current)
        {
            VicePresident *vp = (*current).getValue();
            os << *vp << ", ";
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
    President getPresident() { return this->president; };
    Queue<VicePresident *> getVicePresidentList() { return this->vice_president; };
    std::map<std::string, Company *> getCompanyList()
    {
        return this->company_list;
    };
    Queue<VicePresident *> *getPointerofVicePresidentList()
    {
        return &(this->vice_president);
    };
    std::map<std::string, Company *> *getPointerofCompanyList()
    {
        return &(this->company_list);
    };
    void setName(std::string name) { this->name = name; };
    void setPresident(President *president) { this->president = *president; };
    void setVicePresidentList(const Queue<VicePresident *> &vice_president_list) { this->vice_president = vice_president_list; };
    void setCompanyList(const std::map<std::string, Company *> company_list)
    {
        this->company_list = company_list;
    };

    // METHODS
    void addVicePresident(VicePresident *vice_president) { this->vice_president.Enqueue(vice_president); };
    void addCompany(Company *company)
    {
        this->company_list[company->getName()] = company;
    };
};

Corporation::Corporation(std::string name, President president, Queue<VicePresident *> vice_president, std::map<std::string, Company *> company)
{
    this->name = name;
    this->president = president;
    this->vice_president = vice_president;
    this->company_list = company_list;
}

Corporation::~Corporation()
{
}

#endif
