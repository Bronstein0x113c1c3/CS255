#ifndef MAKECORPORATION_H
#define MAKECORPORATION_H

#include "../UserLib/Corporation.h"
#include "../UserLib/ValidateRegex.h"

// MAKE CORPRATION
Corporation makeCorporationFromFile(std::string file_path);
Corporation makeCorporationFromTerminal();

// VALIDATE NAME FUNCTION
std::string getNameAfterValidate(std::string place, std::string name);

// VALIDATE NUM FUNCTION
std::string getNumAfterValidate(std::string num);

Corporation makeCorporationFromFile(std::string file_path)
{
    Corporation corporation = Corporation();
    return corporation;
}

Corporation makeCorporationFromTerminal()
{
    // SET FLAG
    Corporation corporation = Corporation();
    
    // CORPORATION ATTRIBUTE
    std::string corporation_name;
    std::string company_name;
    std::string department_name;

    // THIS PART IS TO MAKE THE CORPORATIONS, COMPANIES, DEPARTMENTS
    std::cout << "-----------------------Welcome to CORPORATION maker-----------------------" << std::endl;

    std::cout << "Enter Corporation Name: ";
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
        std::cout << "Number of Departments in " << company_name << " :";
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

    return corporation;
}

// DO SOME INT VALIDATION FUNCTION
std::string getNumAfterValidate(std::string num)
{
    while (true)
    {
        if (validateNum(num))
        {
            return num;
        }
        std::cout << "Wrong Format" << std::endl;
        std::cout << "Enter Num Again: ";
        std::cin >> num;
    }
}

// DO SOME STRING VALIDATION FUNCTION
std::string getNameAfterValidate(std::string place, std::string name)
{
    while (true)
    {
        if (validateNameFromTerminal(name))
        {
            return name;
        }
        std::cout << "Wrong Format" << std::endl;
        std::cout << "Enter " << place << " Name Again: ";
        std::cin >> name;
    }
}

#endif