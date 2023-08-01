#ifndef MAKECORPORATION_H
#define MAKECORPORATION_H

#include "../UserLib/Corporation.h"
#include "../UserLib/ValidateRegex.h"

Corporation makeCorporationFromFile(std::string file_path);
Corporation makeCorporationFromTerminal();

Corporation makeCorporationFromFile(std::string file_path)
{
    Corporation corporation = Corporation();

}

Corporation makeCorporationFromTerminal() 
{
    Corporation corporation = Corporation();

    // CORPORATION ATTRIBUTE
    std::string corporation_name;
    std::string company_name;
    std::string department_name;

    // THIS PART IS TO MAKE THE CORPORATIONS, COMPANIES, DEPARTMENTS
    std::cout << "-----------------------Welcome to CORPORATION maker-----------------------" << std::endl;

    do
    {
        std::cout << "Enter Corporation Name: ";
        std::cin >> corporation_name;

        if (validateCorporationName(corporation_name))
        {
            corporation.setName(corporation_name);
            break;
        }

    } while (true);

    int amountCompany = 0;
    std::cout << "How many Company you want to make in " << corporation_name << " Corporation: ";

    return corporation;
}



#endif