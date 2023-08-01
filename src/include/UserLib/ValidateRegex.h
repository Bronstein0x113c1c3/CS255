#ifndef VALIDATEREGEX_H
#define VALIDATEREGEX_H

#include <string>
#include <regex>

//* VALIDATE HUMAN ATTRIBUTE FUNCTIONS
bool validateID(std::string ID);
bool validateName(std::string name);
bool validatePosition(std::string posistion_name);
bool validateDate(std::string date);
bool validateBirthPlace(std::string birth_place);
bool validateEmail(std::string email);
bool validatePhoneNum(std::string phone_num);

//* VALIDATE CORPORATION NAME, COMPANY NAME, DEPARTMENT NAME
bool validateCorporationName(std::string department_name);
bool validateCompanyName(std::string company_name);
bool validateDepartmentName(std::string department_name);

//? VALIDATE OTHER UTILITIES
bool validateFileTxt(std::string filename);

//-------------------------------------------------------------------

//* VALIDATE HUMAN ATTRIBUTE FUNCTIONS
bool validateNum(std::string ID)
{
    return std::regex_match(ID, std::regex("([0-9])+"));
}

bool validateName(std::string name)
{
    return (std::regex_match(name, std::regex("(([A-Z]{1}[a-z]+)\\s?){1,}")));
}

bool validatePosition(std::string posistion_name)
{
    return std::regex_match(posistion_name, std::regex("(([A-Z]{1}[a-z]+)?){1,}"));
}

bool validateDate(std::string date)
{
    std::regex date_pattern("*(((0[1-9]|[12]\\d|3[01])\\/(0[13578]|1[02])\\/((19|[2-9]\\d)\\d{2}))|((0[1-9]|[12]\\d|30)\\/(0[13456789]|1[012])\\/((19|[2-9]\\d)\\d{2}))|((0[1-9]|1\\d|2[0-8])\\/02\\/((19|[2-9]\\d)\\d{2}))|(29\\/02\\/((1[6-9]|[2-9]\\d)(0[48]|[2468][048]|[13579][26])|((16|[2468][048]|[3579][26])00))))");
    return std::regex_match(date, date_pattern);
}

bool validatePlace(std::string place)
{
    std::regex place_pattern("[A-Z]{1}[a-z]+");
    return std::regex_match(place, place_pattern);
}

bool validateEmail(std::string email)
{
    std::regex email_pattern("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}");
    return std::regex_match(email, email_pattern);
}

bool validatePhoneNum(std::string phone_num)
{
    std::regex phone_num_pattern("0[0-9]{10,11}");
    return std::regex_match(phone_num, phone_num_pattern);
}

// * VALIDATE CORPORATION NAME, COMPANY NAME, DEPARTMENT NAME FROM FILE
bool validateCorporationNameFrom(std::string department_name)
{
    std::regex department_pattern("([A-Z]{3}[a-z]+)");
    return std::regex_match(department_name, department_pattern);
}

bool validateCompanyNameFrom(std::string company_name)
{
    std::regex company_pattern("([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)");
    return std::regex_match(company_name, company_pattern);
}

bool validateDepartmentNameFrom(std::string department_name)
{
    std::regex department_pattern("([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)");
    return std::regex_match(department_name, department_pattern);
}

//? VALIDATE OTHER UTILITIES
bool validateFileTxt(std::string filename)
{
    std::regex filename_pattern("^[^\\s](.*).txt$");
    return std::regex_match(filename, filename_pattern);
}

#endif