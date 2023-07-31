#ifndef USERINTERACTIONS_H
#define USERINTERACTIONS_H

#include "../UserLib/Corporation.h"
#include "../UserLib/Company.h"
#include "../UserLib/Department.h"
#include "../UserLib/Human.h"
#include "../DSA/Stack.h"

// ALL THE REQUIREMENTS FUNCTION
void displayCorporationInfo(const Corporation &corporation);
Stack<Human> searchByName(const std::string name_input);
void displayHumanInfo(const int ID);
void displayUnitInfo(const Company &company);
void displayUnitInfo(const Department &department);
void addHuman(const Human new_human);
void updateHumanInfo(const Human &human);
void exitProgram();

#endif