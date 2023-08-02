#ifndef MAKECORPORATION_H
#define MAKECORPORATION_H

#include "../UserLib/Corporation.h"
#include "ValidateNumAndName.h"

// MAKE CORPRATION
Corporation makeCorporationFromFile(std::string file_path);
Corporation makeCorporationFromTerminal();

Corporation makeCorporationFromFile(std::string file_path)
{
    Corporation corporation = Corporation();
    std::ifstream fs(file_path);
    std::string line;
    // std::cout << "HELLO" << std::endl;
    while (getline(fs, line))
    {
        std::regex pattern("(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+){0,1};\\s");
        smatch list_of_data;
        if (std::regex_search(line, list_of_data, pattern))
        {
            // if (validateCompanyNameFromFile(list_of_data[3]))
            // {
            //     std::regex pattern("([A-Z]{3}[a-z]+)");
            //     std::smatch company;
            //     if (std::regex_search(list_of_data[3], company, pattern))
            //     {
            //         std::cout << "Corporation: " << company[1] << endl;
            //     }
            // }
            if (validateCorporationNameFromFile(list_of_data[3]))
            {
                std::cout << "Corporation mode: " << list_of_data[3] << std::endl;
                std::tuple<std::string> result = extractCorporationFromFile(list_of_data[3]);
                std::string corporation_name;
                std::tie(corporation_name) = result;
                std::cout << corporation_name << std::endl;
                // CREATE CORPORATION
                // corporation.setName(corporation_name);
            }
            else if (validateCompanyNameFromFile(list_of_data[3]))
            {
                std::cout << "Company mode: " << list_of_data[3] << std::endl;
                std::tuple<std::string, std::string> result = extractCompanyFromFile(list_of_data[3]);
                std::string corporation_name;
                std::string company_name;
                std::tie(corporation_name, company_name) = result;
                std::cout << corporation_name << std::endl;
                std::cout << company_name << std::endl;
                // CREATE CORPORATION
                // corporation.setName(corporation_name);

                // // CREATE COMPANY
                // Company company = Company();
                // company.setName(company_name);

                // // BEFORE ASSIGN COMPANY -> CHECK AVAILABLE COMPANY && CHECK SIZE
                // corporation.addCompany(company);
            }
            else if (validateDepartmentNameFromFile(list_of_data[3]))
            {
                std::cout << "Department mode: " << list_of_data[3] << std::endl;
                std::tuple<std::string, std::string, std::string> result = extractDepartmentFromFile(list_of_data[3]);
                std::string corporation_name;
                std::string company_name;
                std::string department_name;

                std::tie(corporation_name, company_name, department_name) = result;
                std::cout << corporation_name << std::endl;
                std::cout << company_name << std::endl;
                std::cout << department_name << std::endl;

                // CREATE CORPORATION
                corporation.setName(corporation_name);

                // CREATE COMPANY
                Company company = Company();
                company.setName(company_name);

                // BEFORE ASSIGN COMPANY -> CHECK AVAILABLE COMPANY && CHECK SIZE
                // IF SIZE == 0 -> ASSIGN
                // IF CHECK NOT AVAILABLE -> ASSIGN TO LIST

                // CREATE DEPARTMENT
                Department department = Department();
                department.setName(department_name);

                // BEFORE ASSIGN COMPANY -> CHECK AVAILABLE DEPARTMENT && CHECK SIZE
                // IF SIZE == 0 -> ASSIGN
                company.addDepartment(department);
                corporation.addCompany(company);
                // IF CHECK NOT AVAILABLE -> ASSIGN TO LIST
            }
        }
    }
    return corporation;
}

Corporation makeCorporationFromTerminal()
{
    //! SET FLAG
    Corporation corporation = Corporation();

    // WELCOME
    std::cout << "-----------------------Welcome to CORPORATION maker-----------------------" << std::endl;

    // CORPORATION ATTRIBUTE
    std::string corporation_name = "";

    // THIS PART IS TO MAKE THE CORPORATIONS, COMPANIES, DEPARTMENTS
    std::cout << "Enter Corporation Name: ";
    std::cin >> corporation_name;

    // Ignore the new line character
    std::cin.ignore();

    //! DO SOME STRING VALIDATIONS
    corporation_name = getNameAfterValidate("Corporation", corporation_name);
    
    corporation.setName(corporation_name);

    int amountCompanyWantToCreate = 0;
    std::string string_amountCompanyWantToCreate = "";
    std::cout << "Number of Company in " << corporation_name << " Corporation: ";
    std::cin >> string_amountCompanyWantToCreate;

    // IGNORE THE WHITE SPACE and the newline
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //! DO SOME INTEGER VALIDATIONS
    string_amountCompanyWantToCreate = getNumAfterValidate(string_amountCompanyWantToCreate);
    amountCompanyWantToCreate = stoi(string_amountCompanyWantToCreate);

    for (int amountHasCreated = 1; amountHasCreated <= amountCompanyWantToCreate; amountHasCreated++)
    {
        std::string company_name = "";
        std::cout << "Enter Company " << amountHasCreated << " Name: ";
        std::cin >> company_name;

        // Ignore the new line character
        std::cin.ignore();

        //! DO SOME STRING VALIDATIONS
        company_name = getNameAfterValidate("Company", company_name);

        //* ADD COMPANY TO CORPORATION
        Company new_company = Company();
        new_company.setName(company_name);
        corporation.addCompany(new_company);

        // ASK HOW MANY DEPARTMENTS THEY WANT TO ADD
        int amountDepartmentWantToCreate = 0;
        std::string string_amountDepartmentWantToCreate = "";
        std::cout << "Number of Departments in " << company_name << ":";
        std::cin >> string_amountDepartmentWantToCreate;

        // IGNORE THE WHITE SPACE and the newline
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //! DO SOME INTEGER VALIDATIONS
        string_amountDepartmentWantToCreate = getNumAfterValidate(string_amountDepartmentWantToCreate);
        amountDepartmentWantToCreate = stoi(string_amountDepartmentWantToCreate);

        for (int amountHasCreated = 1; amountHasCreated <= amountDepartmentWantToCreate; amountHasCreated++)
        {
            std::string deptName = "";
            std::cout << "Enter Department " << amountHasCreated << " Name: ";
            std::cin >> deptName;

            // Ignore the new line character
            std::cin.ignore();

            //! DO SOME STRING VALIDATIONS
            deptName = getNameAfterValidate("Department", deptName);

            //* ADD DEPARTMENT TO COMPANY
            Department new_dept = Department();
            new_dept.setName(deptName);
            new_company.addDepartment(new_dept);
        }
    }

    return corporation;
}

#endif