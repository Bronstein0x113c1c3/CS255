#ifndef MAKECORPORATION_H
#define MAKECORPORATION_H

#include "../UserLib/Corporation.h"
#include "ValidateNumAndName.h"

// MAKE CORPRATION
HashMap<std::string, Corporation> makeCorporationFromFile(std::string file_path);
HashMap<std::string, Corporation> makeCorporationFromTerminal();

HashMap<std::string, Corporation> makeCorporationFromFile(std::string file_path)
{
    HashMap<std::string, Corporation> corporations;
    std::ifstream fs(file_path);
    std::string line;
    while (getline(fs, line))
    {
        std::regex pattern("(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+){0,1};\\s");
        smatch list_of_data;
        if (std::regex_search(line, list_of_data, pattern))
        {
            if (validateCompanyNameFromFile(list_of_data[3]))
            {
                regex pattern("([A-Z]{3}[a-z]+)");
                smatch company;
                if (std::regex_search(list_of_data[3], company, pattern))
                {
                    std::cout << "Corporation: " << company[1] << endl;
                }
            }
        }
    }
    return corporations;
}

HashMap<std::string, Corporation> makeCorporationFromTerminal()
{
    //! SET FLAG
    HashMap<std::string, Corporation> corporations;

    // WELCOME
    std::cout << "-----------------------Welcome to CORPORATION maker-----------------------" << std::endl;

    int amountCorporationsWantToCreate = 0;
    std::string string_amountCorporationsWantToCreate = "";

    std::cout << "Number of Corporations To Make: ";
    std::cin >> string_amountCorporationsWantToCreate;

    //! DO SOME STRING VALIDATIONS
    string_amountCorporationsWantToCreate = getNumAfterValidate(string_amountCorporationsWantToCreate);
    amountCorporationsWantToCreate = stoi(string_amountCorporationsWantToCreate);

    for (int corporationHasCreated = 1; corporationHasCreated <= amountCorporationsWantToCreate; corporationHasCreated++)
    {
        Corporation corporation = Corporation();

        // CORPORATION ATTRIBUTE
        std::string corporation_name;
        std::string company_name;
        std::string department_name;

        // THIS PART IS TO MAKE THE CORPORATIONS, COMPANIES, DEPARTMENTS
        std::cout << "Enter Corporation " << corporationHasCreated << " Name: ";
        std::cin >> corporation_name;

        //! DO SOME STRING VALIDATIONS
        corporation_name = getNameAfterValidate("Corporation", corporation_name);
        corporation.setName(corporation_name);

        int amountCompanyWantToCreate = 0;
        std::string string_amountCompanyWantToCreate;
        std::cout << "Number of Company in " << corporation_name << " Corporation: ";
        std::cin >> string_amountCompanyWantToCreate;

        //! DO SOME INTEGER VALIDATIONS
        string_amountCompanyWantToCreate = getNumAfterValidate(string_amountCompanyWantToCreate);
        amountCompanyWantToCreate = stoi(string_amountCompanyWantToCreate);

        for (int amountHasCreated = 1; amountHasCreated <= amountCompanyWantToCreate; amountHasCreated++)
        {
            std::string company_name;
            std::cout << "Enter Company " << amountHasCreated << " Name: ";
            std::cin >> company_name;

            //! DO SOME STRING VALIDATIONS
            company_name = getNameAfterValidate("Company", company_name);

            //* ADD COMPANY TO CORPORATION
            Company new_company = Company();
            new_company.setName(company_name);
            corporation.addCompany(new_company);

            // ASK HOW MANY DEPARTMENTS THEY WANT TO ADD
            int amountDepartmentWantToCreate = 0;
            std::string string_amountDepartmentWantToCreate;
            std::cout << "Number of Departments in " << company_name << ":";
            std::cin >> string_amountDepartmentWantToCreate;

            //! DO SOME INTEGER VALIDATIONS
            string_amountDepartmentWantToCreate = getNumAfterValidate(string_amountDepartmentWantToCreate);
            amountDepartmentWantToCreate = stoi(string_amountDepartmentWantToCreate);

            for (int amountHasCreated = 1; amountHasCreated <= amountDepartmentWantToCreate; amountHasCreated++)
            {
                std::string deptName;
                std::cout << "Enter Department " << amountHasCreated << " Name: ";
                std::cin >> deptName;

                //! DO SOME STRING VALIDATIONS
                deptName = getNameAfterValidate("Department", deptName);

                //* ADD DEPARTMENT TO COMPANY
                Department new_dept = Department();
                new_dept.setName(deptName);
                new_company.addDepartment(new_dept);
            }
        }

        //? ASSIGN TO THE HASH MAP AFTER COMPLETION
        corporations.assign(corporation.getName(), corporation);
    }

    return corporations;
}

#endif