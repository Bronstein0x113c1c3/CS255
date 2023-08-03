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

// ADJUST FUNCTIONS USING TERMINAL
void addHuman(const Corporation &corporation);        //! USE searchByID() -> IF Yes -> Update to new One ? || IF No -> Add new One
void updateHumanInfo(const Corporation &corporation); //! USE searchByID() -> IF Yes -> Update to new One ? || IF No -> Add new One
void addDaysWorked(const Human &human);

// WRITE TO FILE
void writeToFileTxt(const Corporation &corporation, std::string file_path);

// EXIT FUNCTION
void exitProgram();

//-----------------------------------------------------------------------------------------------

// DISPLAY PURPOSE ONLY
// Result: images\Output.png
void displayCorporationInfo(const Corporation &corporation);
void displayHumanInfo(const int ID); //! USE searchByID()
void displayUnitInfo(const Company &company);
void displayUnitInfo(const Department &department);

// MAKE CORPORATION use file_path to extract data from a FILE
// DEFAULT: it will get Input from TERMINAL to MAKE COPORATION
Corporation makeCorporation(std::string file_path)
{
    // IF THE FILE PATH IS EMPTY
    // -> DO THE TERMINAL PART
    Corporation corporation;
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

// ADD HUMAN will get Input from TERMINAL to MAKE HUMAN
void addHuman(const Corporation &corporation)
{
    //* MAKE HUMAN
    Human human = Human();

    //* HUMAN ATTRIBUTES
    int ID = 0;
    std::string string_ID = "";
    std::string name = "";
    std::string first_name = "";
    std::string last_mid_name = "";
    std::string work_place = "";
    std::string position = "";
    std::string date_of_birth = "";
    std::string birth_place = "";
    std::string email = "";
    std::string phone_num = "";
    std::string first_day_at_work = "";

    // WELCOME
    std::cout << "-----------------------TIME TO MAKE SOME EMPLOYEE-----------------------" << std::endl;

    //* GET INPUT
    //? ID
    std::cout << "Enter ID: ";
    std::cin >> string_ID;

    // IGNORE THE NEW LINE CHARACTER
    std::cin.ignore();

    //! DO SOME INTEGER VALIDATIONS
    string_ID = getValueAfterValidate(string_ID, validateNum);
    ID = stoi(string_ID);
    human.setID(ID);

    //!! VALIDATE ID ??

    //? Name
    std::cout << "Enter NAME: ";
    std::cin >> name;

    // IGNORE THE NEW LINE CHARACTER
    std::cin.ignore();

    //! DO SOME STRING VALIDATIONS and DO SOME STRING EXTRACT
    name = getValueAfterValidate(name, validateName);
    std::tuple<std::string, std::string> name_extracted = extractName(name);

    first_name = std::get<0>(name_extracted);
    last_mid_name = std::get<1>(name_extracted);
    human.setFirstName(first_name);
    human.setLastMidName(last_mid_name);

    //? WORK PLACE
    //? WORK PLACE + POSITION -> ASSIGN TO THE EQUIVALENT CORPORATION position
    std::cout << "Enter WORK PLACE" << std::endl;
    std::cout << "Corporation or Company or Department: ";
    std::cin >> work_place;

    // IGNORE THE NEW LINE CHARACTER
    std::cin.ignore();

    //! DO SOME STRING VALIDATIONS
    // IF THE USER TYPE UNVAILABLE
    while (work_place != "Corporation" || work_place != "Company" || work_place != "Department")
    {
        if (work_place == "Corporation" || work_place == "Company" || work_place == "Department")
        {
            break;
        }
        std::cout << "Enter WORK PLACE again" << std::endl;
        std::cout << "Corporation or Company or Department: ";
        std::cin >> work_place;

        // IGNORE THE NEW LINE CHARACTER
        std::cin.ignore();
    }
    
    human.setWorkPlace(work_place);

    //? EVALUATE POSITION BASED ON WORK PLACE
    //? POSITION
    if (work_place == "Corporation")
    {
        std::cout << "Enter POSITION: " << std::endl;
        std::cout << "President or Vice President: ";
        std::cin >> position;
        position = getValueAfterValidate(position, validateCorporationPosition);
    }
    else if (work_place == "Company")
    {
        std::cout << "Enter POSITION: " << std::endl;
        std::cout << "Director or Vice Director: ";
        std::cin >> position;
        position = getValueAfterValidate(position, validateCompanyPosition);
    }
    else if (work_place == "Department")
    {
        std::cout << "Enter POSITION: " << std::endl;
        std::cout << "Manager or Deputy Manager or Employee: ";
        std::cin >> position;
        position = getValueAfterValidate(position, validateDepartmentPosition);
    }
    // IGNORE THE NEW LINE CHARACTER
    std::cin.ignore();

    human.setPosition(position);

    //? DATE OF BIRTH
    std::cout << "Enter DATE OF BIRTH: ";
    std::cin >> date_of_birth;

    // IGNORE THE NEW LINE CHARATER
    std::cin.ignore();

    date_of_birth = getValueAfterValidate(date_of_birth, validateDate);
    human.setDateOfBirth(date_of_birth);

    //? BIRTH PLACE
    std::cout << "Enter BIRTH PLACE: ";
    std::cin >> birth_place;

    // IGNORE THE NEW LINE CHARACTER
    std::cin.ignore();

    birth_place = getValueAfterValidate(birth_place, validatePlace);
    human.setBirthPlace(birth_place);

    //? EMAIL
    std::cout << "Enter EMAIL: ";
    std::cin >> email;

    // IGNORE THE NEW LINE CHARACTER
    std::cin.ignore();

    email = getValueAfterValidate(email, validateEmail);
    human.setEmail(email);

    //? PHONE NUM
    std::cout << "Enter PHONE NUMBER: ";
    std::cin >> phone_num;

    // IGNORE THE NEW LINE CHARACTER
    std::cin.ignore();

    phone_num = getValueAfterValidate(phone_num, validatePhoneNum);
    human.setPhoneNum(phone_num);

    //? FIRST DAY AT WORK
    std::cout << "Enter FIRST DAY AT WORK follow the format dd/mm/yyyy: ";
    std::cin >> first_day_at_work;

    first_day_at_work = getValueAfterValidate(first_day_at_work, validateDate);
    human.setFirstDayAtWork(first_day_at_work);

    
}

#endif