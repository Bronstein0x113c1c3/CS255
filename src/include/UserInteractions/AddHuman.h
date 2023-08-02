#ifndef ADDHUMAN_H
#define ADDHUMAN_H

#include "../UserLib/Human.h"
#include "../UserLib/Corporation.h"
#include "../UserLib/ValidateRegex.h"

// GET HUMAN FUNCTION
Human addHumanFromFile(const Corporation &corporation, const std::string file_path);
Human addHumanFromTerminal(const Corporation &corporation);

// VALIDATE NAME FUNCTION
std::string getNameAfterValidate(std::string place, std::string name);

// VALIDATE NUM FUNCTION
std::string getNumAfterValidate(std::string num);

Human addHumanFromFile(const Corporation &corporation, const std::string file_path)
{
}

Human addHumanFromTerminal(const Corporation &corporation)      //! DUY PART
{
    //* HUMAN ATTRIBUTES
    int ID = 0;
    std::string name = "";
    std::string work_place = "";
    std::string position = "";
    std::string date_of_birth = "";
    std::string birth_place = "";
    std::string email = "";
    std::string phone_num = "";
    std::string first_day_at_work = "";

    //* GET INPUT
    
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