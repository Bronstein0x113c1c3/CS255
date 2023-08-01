#ifndef USERINTERACTIONS_H
#define USERINTERACTIONS_H

#include "../UserLib/Corporation.h"
#include "../UserLib/Company.h"
#include "../UserLib/Department.h"
#include "../UserLib/Human.h"
#include "../DSA/Stack.h"
#include "../UserLib/ValidateRegex.h"
#include "GetHuman.h"
#include "MakeCorporation.h"

// ALL THE REQUIREMENTS FUNCTION

// MAKE FUNCTIONS
Corporation makeCorporation(std::string file_path = "");

// GET INPUT FUNCTIONS
Human getHuman(std::string file_path = "");

// DISPLAY FUNCTIONS
void displayCorporationInfo(const Corporation &corporation);
void displayHumanInfo(const int ID);
void displayUnitInfo(const Company &company);
void displayUnitInfo(const Department &department);

// SEARCH FUNCTIONS
Stack<Human> searchByName(const std::string name_input);
Human searchByID(const int ID);

// ADJUST FUNCTIONS
void addHuman(const Human &new_human);
void updateHumanInfo(const Human &human);

// WRITE TO FILE
void writeToFileTxt(const Corporation &corporation, std::string file_path);

// EXIT FUNCTION
void exitProgram();

//-----------------------------------------------------------------------------------------------

// MAKE CORPORATION use file_path to extract data from a FILE
// DEFAULT: it will get Input from TERMINAL
Corporation makeCorporation(std::string file_path)
{
    // IF THE FILE PATH IS EMPTY
    // -> DO THE TERMINAL PART
    Corporation corporation = Corporation();
    if (file_path != "" && validateFileTxt(file_path)) //! DO THE FILE PART -> DUY PART (AFTER CHECKING DONE)
    {
        corporation = makeCorporationFromFile(file_path);
    }
    else // DO THE TERMINAL PART
    {
        corporation = makeCorporationFromTerminal();
    }

    return corporation;
}

#endif