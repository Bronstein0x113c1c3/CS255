#ifndef VALIDATENUMANDNAME_H
#define VALIDATENUMANDNAME_H

#include <iostream>
#include "../UserLib/ValidateRegex.h"

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