#ifndef CORPORATION_H
#define CORPORATION_H
#include <string>
#include <iostream>
#include "Human.h"
#include "../DSA/Queue.h"
#include "Company.h"
class Corporation
{
private:
    std::string name = "BKCorporation";
    President president;
    Queue<VicePresident> vice_president;
    Queue<Company> company_list;

public:
    // CONSTRUCTORS
    Corporation(){};
    Corporation(std::string name, President president, Queue<VicePresident> vice_president, Queue<Company> company);
    ~Corporation();

    // OPERATORS
    friend ostream &operator<<(ostream &os, const Corporation &corporation)
    {
        os << corporation.name << std::endl
           << corporation.president << std::endl
           << corporation.vice_president << std::endl
           << corporation.company_list << std::endl;
        return os;
    }

    // PROPERTIES
    std::string getName() { return this->name; };
    President getPresident() { return this->president; };
    Queue<VicePresident> getVicePresidentList() { return this->vice_president; };
    Queue<Company> getCompanyList() { return this->company_list; };

    void setName(std::string name) { this->name = name; };
    void setPresident(President president) { this->president = president; };
    void setVicePresidentList(const Queue<VicePresident> &vice_president_list) { this->vice_president = vice_president_list; };
    void setCompanyList(const Queue<Company> &company_list) { this->company_list = company_list; };

    // METHODS
    void addVicePresident(VicePresident vice_president) { this->vice_president.Enqueue(vice_president); };
    void addCompany(Company company) { this->company_list.Enqueue(company); };
    bool operator==(const Corporation& otherCorporation);
};

Corporation::Corporation(std::string name, President president, Queue<VicePresident> vice_president, Queue<Company> company)
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
