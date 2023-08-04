#ifndef USERINTERACTIONS_H
#define USERINTERACTIONS_H

#include "../UserLib/Corporation.h"
#include "../UserLib/Company.h"
#include "../UserLib/Department.h"
#include "../UserLib/Human.h"
#include "../DSA/Stack.h"
#include "../DSA/HashMap.h"
#include "../UserLib/ValidateRegex.h"
#include "ValidateNumAndName.h"
#include "MakeCorporation.h"
#include "AddAndUpdateHuman.h"
#include "SearchByName.h"
#include "AddDaysWorked.h"

// ALL THE REQUIREMENTS FUNCTION

// MAKE FUNCTIONS
Corporation *makeCorporation(std::string file_path = "");

// DISPLAY FUNCTIONS
void displayCorporationInfo(Corporation *orporation);
void displayHumanInfo(const int ID); //! USE searchByID()
void displayUnitInfo(Company *company);
void displayUnitInfo(Department *department);

// SEARCH FUNCTIONS USE CONCURRENCY - PARRALELISM
Stack<Human> *searchByName(Corporation *corporation, const std::string name_input);
Human *searchByID(Corporation* corporation, const int ID);

// ADJUST FUNCTIONS USING TERMINAL
void addAndUpdateHuman(Corporation *corporation);        //! USE searchByID() -> IF Yes -> Update to new One ? || IF No -> Add new One
void addDaysWorked(Human *human);

// WRITE TO FILE
void writeToFileTxt(const Corporation *corporation, std::string file_path);

// EXIT FUNCTION
void exitProgram();

//-----------------------------------------------------------------------------------------------

// DISPLAY PURPOSE ONLY
// Result: images\Output.png
void displayCorporationInfo(Corporation *corporation);
void displayHumanInfo(const int ID); //! USE searchByID()
void displayUnitInfo(const Company *company);
void displayUnitInfo(const Department *department);

// MAKE CORPORATION use file_path to extract data from a FILE
// DEFAULT: it will get Input from TERMINAL to MAKE COPORATION
Corporation *makeCorporation(std::string file_path)
{
    // IF THE FILE PATH IS EMPTY
    // -> DO THE TERMINAL PART
    Corporation *corporation;
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

// DISPLAY FUNCTIONS
void displayCorporationInfo(Corporation *orporation)
{

}

void displayHumanInfo(const int ID) //! USE searchByID()
{

}

void displayUnitInfo(Company *company)
{

}

void displayUnitInfo(Department *department)
{

}

// EXIT FUNCTION
void exitProgram()
{
    
}

#endif