#ifndef ADDHUMAN_H
#define ADDHUMAN_H

#include "../UserLib/Human.h"
#include "../UserLib/Corporation.h"
#include "ValidateNumAndName.h"

// GET HUMAN FUNCTION
void addHumanFromFile(const Corporation &corporation, const std::string file_path);
void addHumanFromTerminal(const Corporation &corporation);

// VALIDATE NAME FUNCTION
std::string getNameAfterValidate(std::string place, std::string name);

// VALIDATE NUM FUNCTION
std::string getNumAfterValidate(std::string num);

void addHumanFromFile(const Corporation &corporation, const std::string file_path)
{
}

void addHumanFromTerminal(const Corporation &corporation)      //! DUY PART
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


#endif