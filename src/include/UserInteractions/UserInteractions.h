#ifndef USERINTERACTIONS_H
#define USERINTERACTIONS_H

#include "../UserLib/Corporation.h"
#include "../UserLib/Company.h"
#include "../UserLib/Department.h"
#include "../UserLib/Human.h"
#include "../DSA/Stack.h"
#include "../UserLib/ValidateRegex.h"
#include "AddHuman.h"
#include "MakeCorporation.h"

// ALL THE REQUIREMENTS FUNCTION

// MAKE FUNCTIONS
Corporation makeCorporation(std::string file_path = "");

// DISPLAY FUNCTIONS
void displayCorporationInfo(const Corporation &corporation);
void displayHumanInfo(const int ID); //! USE searchByID()
void displayUnitInfo(const Company &company);
void displayUnitInfo(const Department &department);

// SEARCH FUNCTIONS USE CONCURRENCY - PARRALELISM
Stack<Human> searchByName(const std::string name_input);
Human searchByID(const int ID);

// CHECKING FUNCTION
bool isHumanExist(const Human &human); //! USE searchByID() to return True or False

// ADJUST FUNCTIONS
void addHuman(const Corporation &corporation, std::string file_path = ""); //! USE searchByID() -> IF Yes -> Update to new One ? || IF No -> Add new One
void updateHumanInfo(const Corporation &corporation, const Human &human);  //! USE searchByID() -> IF Yes -> Update to new One ? || IF No -> Add new One

// WRITE TO FILE
void writeToFileTxt(const Corporation &corporation, std::string file_path);

// EXIT FUNCTION
void exitProgram();

//-----------------------------------------------------------------------------------------------

// MAKE CORPORATION use file_path to extract data from a FILE
// DEFAULT: it will get Input from TERMINAL to MAKE COPORATION
Corporation makeCorporation(std::string file_path)
{
    // IF THE FILE PATH IS EMPTY
    // -> DO THE TERMINAL PART
    Corporation corporation = Corporation();
    if (file_path != "" && validateFileTxt(file_path)) 
    {
        corporation = makeCorporationFromFile(file_path);
    }
    else // DO THE TERMINAL PART
    {
        corporation = makeCorporationFromTerminal();
    }

    return corporation;
}

// ADD HUMAN use file_path to extract data from a FILE
// DEFAULT: it will get Input from TERMINAL to MAKE HUMAN
void addHuman(const Corporation &corporation, std::string file_path = "")
{
    // IF THE FILE PATH IS EMPTY
    // -> DO THE TERMINAL PART
    if (file_path != "" && validateFileTxt(file_path))
    {
        addHumanFromFile(corporation, file_path);
    }
    else // DO THE TERMINAL PART
    {
        addHumanFromTerminal(corporation);
    }
}

#endif