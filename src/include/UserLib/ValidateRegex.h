#ifndef VALIDATEREGEX_H
#define VALIDATEREGEX_H

#include <regex>
#include <string>

bool validateID(std::string ID);
bool validateName(std::string name);
bool validateDepartmentName(std::string department_name);
bool validatePosition(std::string posistion_name);
bool validateDate(std::string date);
bool validateBirthPlace(std::string birth_place);
bool validateEmail(std::string email);
bool validatePhoneNum(std::string phone_num);

#endif