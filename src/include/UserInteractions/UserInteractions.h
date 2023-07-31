#ifndef USERINTERACTIONS_H
#define USERINTERACTIONS_H

#include "../UserLib/Corporation.h"
#include "../UserLib/Company.h"
#include "../UserLib/Department.h"
#include "../UserLib/Human.h"
#include "../DSA/Stack.h"

// ALL THE REQUIREMENTS FUNCTION

// DISPLAY FUNCTIONS
void displayCorporationInfo(const Corporation &corporation);
void displayHumanInfo(const int ID);
void displayUnitInfo(const Company &company);
void displayUnitInfo(const Department &department);

// SEARCH FUNCTIONS
Stack<Human> &searchByName(const std::string name_input);
Human &searchByID(const int ID);

// ADJUST FUNCTIONS
void addHuman(const Human &new_human);
void updateHumanInfo(const Human &human);

// EXIT FUNCTION
void exitProgram();

#endif