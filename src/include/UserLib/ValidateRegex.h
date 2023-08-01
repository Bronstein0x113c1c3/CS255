#ifndef VALIDATEREGEX_H
#define VALIDATEREGEX_H

#include <string>
#include <regex>

// VALIDATE REGEX FUNCTIONS
bool validateID(std::string ID);
bool validateName(std::string name);
bool validateDepartmentName(std::string department_name);
bool validatePosition(std::string posistion_name);
bool validateDate(std::string date);
bool validateBirthPlace(std::string birth_place);
bool validateEmail(std::string email);
bool validatePhoneNum(std::string phone_num);

bool validateName(std::string name){
    return (std::regex_match(name,std::regex("(([A-Z]{1}[a-z]+)\\s?){1,}")));
}
bool validateID(std::string ID){
    return std::regex_match(ID,std::regex("([0-9])+"));
}
bool validateDepartmentName(std::string department_name){
    return std::regex_match(department_name,std::regex("([A-Za-z])+"));
}
bool validatePosition(std::string posistion_name){
    return std::regex_match(posistion_name,std::regex("([A-Za-z])+"));

}

bool validateDate(std::string date)
{
    std::regex date_pattern("([0-9]{2})(?:-|.|\\/)([0-9]{1,2})(?:-|.|\\/)([0-9]{4})");
    return std::regex_match(date, date_pattern);
}

bool validateBirthPlace(std::string date)
{
    return true;   
}

bool validateEmail(std::string email)
{
    return true;
}

bool validatePhoneNum(std::string phone_num)
{
    return true;
}
#endif