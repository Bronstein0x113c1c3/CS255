#ifndef ADDDAYSWORKED_H
#define ADDDAYSWORKED_H

#include "../UserLib/Human.h"
#include "../UserLib/Record.h"
#include "../UserLib/ValidateRegex.h"
#include "ValidateNumAndName.h"


void addDaysWorked(Human *human)
{
    std::string day_work;

    std::cout << "Enter the Day you have work: ";
    std::getline(std::cin, day_work);

    day_work = getValueAfterValidate(day_work, validateDate);

    
}

#endif