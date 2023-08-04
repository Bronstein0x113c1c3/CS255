#ifndef MAKECORPORATION_H
#define MAKECORPORATION_H

#include "../UserLib/Corporation.h"
#include "../UserLib/Human.h"
#include "ValidateNumAndName.h"

// MAKE CORPRATION
// Corporation *makeCorporationFromFile(std::string file_path);
Corporation *makeCorporationFromTerminal();
Corporation *buildCorporationFromFile(std::string file_path)
{
    // Instantiate the corporation, new corporation
    Corporation *corp = new Corporation();
    std::ifstream fs(file_path);
    std::string line;

    /*
    The real shit comes here!
    */
    while (getline(fs, line))
    {
        std::regex pattern("(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+){0,1};\\s");
        std::smatch list_of_field;
        if (std::regex_search(line, list_of_field, pattern))
        {
            cout << "Valid line: " << line << endl;
            std::string last_mid_name, first_name;
            std::tie(last_mid_name, first_name) = extractName(list_of_field[2]);

            if (validateCorporationNameFromFile(list_of_field[3]))
            {
                
                // Set the name for corporation:
                std::tuple<std::string> result = extractCorporationFromFile(list_of_field[3]);
                std::string corporation_name;
                std::tie(corporation_name) = result;
                corp->setName(corporation_name);
            }
            else if (validateCompanyNameFromFile(list_of_field[3]))
            {
                std::string corporation_name, company_name;
                std::tuple<std::string, std::string> result = extractCompanyFromFile(list_of_field[3]);
                std::tie(corporation_name, company_name) = result;
                corp->setName(corporation_name);

                if (!corp->getCompanyList().count(company_name))
                {
                    Company cp = Company();
                    cp.setName(company_name);
                    corp->addCompany(&cp);
                }
                cout << "Name after creating company " << (corp->getCompanyList())[company_name]->getName() << endl;
                // let add something....
            }
            else if (validateDepartmentNameFromFile(list_of_field[3]))
            {
                std::string corporation_name, company_name, department_name;
                std::tuple<std::string, std::string, std::string> result = extractDepartmentFromFile(list_of_field[3]);
                std::tie(corporation_name, company_name, department_name) = result;
                if (!corp->getCompanyList().count(company_name))
                {
                    Department d = Department();
                    d.setName(department_name);
                    Company cp = Company();
                    cp.setName(company_name);
                    cp.addDepartment(&d);
                    corp->addCompany(&cp);
                }
                else
                {
                    if (!((*(corp->getPointerofCompanyList()))[company_name]->getDepartmentList().count(department_name)))
                    {
                        Department d = Department();
                        d.setName(department_name);
                        (*(corp->getPointerofCompanyList()))[company_name]->addDepartment(&d);
                    }
                }
                 cout << "Name after creating company " << (corp->getCompanyList())[company_name]->getName() << endl;
            }
        }
    }
    return corp;
}

Corporation *makeCorporationFromFile(std::string file_path)
{
    // Instantiate the corporation, new corporation
    Corporation *corp = buildCorporationFromFile(file_path);
    std::ifstream fs(file_path);
    std::string line;

    /*
    The real shit comes here!
    */
    while (getline(fs, line))
    {
        std::regex pattern("(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+);\\s(.[^;]+){0,1};\\s");
        std::smatch list_of_field;
        if (std::regex_search(line, list_of_field, pattern))
        {
            std::string last_mid_name, first_name;
            std::tie(last_mid_name, first_name) = extractName(list_of_field[2]);

            if (validateCorporationNameFromFile(list_of_field[3]))
            {
                // Set the name for corporation:
                std::tuple<std::string> result = extractCorporationFromFile(list_of_field[3]);
                std::string corporation_name;
                std::tie(corporation_name) = result;
                corp->setName(corporation_name);
            }
            else if (validateCompanyNameFromFile(list_of_field[3]))
            {
                std::string corporation_name, company_name;
                std::tuple<std::string, std::string> result = extractCompanyFromFile(list_of_field[3]);
                std::tie(corporation_name, company_name) = result;
                corp->setName(corporation_name);

                if (!corp->getCompanyList().count(company_name))
                {
                    Company cp = Company();
                    cp.setName(company_name);
                    corp->addCompany(&cp);
                }
                // let add something....
            }
            else if (validateDepartmentNameFromFile(list_of_field[3]))
            {
                std::string corporation_name, company_name, department_name;
                std::tuple<std::string, std::string, std::string> result = extractDepartmentFromFile(list_of_field[3]);
                std::tie(corporation_name, company_name, department_name) = result;
                if (!corp->getCompanyList().count(company_name))
                {
                    Department d = Department();
                    d.setName(department_name);
                    Company cp = Company();
                    cp.setName(company_name);
                    cp.addDepartment(&d);
                    corp->addCompany(&cp);
                }
                else
                {
                    if (!((*(corp->getPointerofCompanyList()))[company_name]->getDepartmentList().count(department_name)))
                    {
                        Department d = Department();
                        d.setName(department_name);
                        (*(corp->getPointerofCompanyList()))[company_name]->addDepartment(&d);
                    }
                }
            }
        }
    }
    return corp;
}

Corporation *makeCorporationFromTerminal()
{
    //! SET FLAG
    Corporation *corporation = new Corporation();

    // WELCOME
    std::cout << "-----------------------WELCOME TO CORPORATION MAKER-----------------------" << std::endl;

    // CORPORATION ATTRIBUTE
    std::string corporation_name = "";

    // THIS PART IS TO MAKE THE CORPORATIONS, COMPANIES, DEPARTMENTS
    std::cout << "Enter Corporation Name: ";
    std::getline(std::cin, corporation_name);

    // Ignore the new line character
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //! DO SOME STRING VALIDATIONS
    corporation_name = getNameAfterValidate("Corporation", corporation_name);

    corporation->setName(corporation_name);

    int amountCompanyWantToCreate = 0;
    std::string string_amountCompanyWantToCreate = "";
    std::cout << "Number of Company in " << corporation_name << " Corporation: ";
    std::cin >> string_amountCompanyWantToCreate;

    // IGNORE THE WHITE SPACE and the newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //! DO SOME INTEGER VALIDATIONS
    string_amountCompanyWantToCreate = getNumAfterValidate(string_amountCompanyWantToCreate);
    amountCompanyWantToCreate = stoi(string_amountCompanyWantToCreate);

    for (int amountHasCreated = 1; amountHasCreated <= amountCompanyWantToCreate; amountHasCreated++)
    {
        std::string company_name = "";
        std::cout << "Enter Company " << amountHasCreated << " Name: ";
        std::getline(std::cin, company_name);

        // Ignore the new line character
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //! DO SOME STRING VALIDATIONS
        company_name = getNameAfterValidate("Company", company_name);

        //* ADD COMPANY TO CORPORATION
        Company *new_company = new Company();
        new_company->setName(company_name);
        corporation->addCompany(new_company);

        // ASK HOW MANY DEPARTMENTS THEY WANT TO ADD
        int amountDepartmentWantToCreate = 0;
        std::string string_amountDepartmentWantToCreate = "";
        std::cout << "Number of Departments in " << company_name << ":";
        std::cin >> string_amountDepartmentWantToCreate;

        // IGNORE THE WHITE SPACE and the newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //! DO SOME INTEGER VALIDATIONS
        string_amountDepartmentWantToCreate = getNumAfterValidate(string_amountDepartmentWantToCreate);
        amountDepartmentWantToCreate = stoi(string_amountDepartmentWantToCreate);

        for (int amountHasCreated = 1; amountHasCreated <= amountDepartmentWantToCreate; amountHasCreated++)
        {
            std::string deptName = "";
            std::cout << "Enter Department " << amountHasCreated << " Name: ";
            std::getline(std::cin, deptName);

            // Ignore the new line character
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            //! DO SOME STRING VALIDATIONS
            deptName = getNameAfterValidate("Department", deptName);

            //* ADD DEPARTMENT TO COMPANY
            Department *new_dept = new Department();
            new_dept->setName(deptName);
            new_company->addDepartment(new_dept);
        }
    }
    return corporation;
}

#endif