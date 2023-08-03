#ifndef VALIDATENUMANDNAME_H
#define VALIDATENUMANDNAME_H

#include <iostream>
#include <tuple>
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
        std::cout << "Wrong Format!!!" << std::endl;
        std::cout << "Enter Num Again: ";
        std::cin >> num;

        // IGNORE THE WHITE SPACE and the newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        std::cout << "Wrong Format!!!" << std::endl;
        std::cout << "Enter " << place << " Name Again: ";
        std::getline(std::cin, name);

        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// DO THE VALUE VALIDATION FUNCTION
std::string getValueAfterValidate(std::string value, std::function<bool(std::string)> validateFunc)
{
    while (true)
    {
        if (validateFunc(value))
        {
            return value;
        }
        std::cout << "Wrong Format!!!" << std::endl;
        std::cout << "Enter Again: ";
        std::getline(std::cin, value);
    }
}

#endif