#ifndef VALIDATEREGEX_H
#define VALIDATEREGEX_H

#include <string>
#include <regex>
#include <tuple>

//* VALIDATE HUMAN ATTRIBUTE FUNCTIONS
bool validateNum(std::string ID);
bool validateName(std::string name);
bool validatePosition(std::string posistion_name);
bool validateDate(std::string date);
bool validatePlace(std::string birth_place);
bool validateEmail(std::string email);
bool validatePhoneNum(std::string phone_num);

//* VALIDATE CORPORATION NAME, COMPANY NAME, DEPARTMENT NAME FROM FILE
bool validateCorporationNameFromFile(std::string department_name);
bool validateCompanyNameFromFile(std::string company_name);
bool validateDepartmentNameFromFile(std::string department_name);

//* VALIDATE CORPORATION NAME, COMPANY NAME, DEPARTMENT NAME FROM TERMINAL
bool validateNameFromTerminal(std::string name);

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

// EXTRACT CORPORATION, COMPANY AND DEPARTMENT FROM FILE!!!!
bool validateCorporationNameFromFile(std::string corporation_name)
{
    std::regex corporation_pattern("([A-Z]{3}[a-z]+)");
    return std::regex_match(corporation_name, corporation_pattern);
}
tuple<std::string> extractCorporationFromFile(std::string corporation_name)
{
    tuple<std::string> result;
    std::regex corporation_pattern("([A-Z]{3}[a-z]+)");
    smatch list_of_data;
    if (regex_search(corporation_name, list_of_data, corporation_pattern))
    {
        // result = make_tuple(list_of_data[1]);
        return tuple<std::string>(list_of_data[1]);
    }
    return tuple<std::string>("Corporation");
}
bool validateCompanyNameFromFile(std::string company_name)
{
    std::regex company_pattern("([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)");
    return std::regex_match(company_name, company_pattern);
}
tuple<std::string, std::string> extractCompanyFromFile(std::string company_name)
{
    tuple<std::string, std::string> result;
    std::regex corporation_pattern("([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)");
    smatch list_of_data;
    if (regex_search(company_name, list_of_data, corporation_pattern))
    {
        // result = make_tuple(list_of_data[1], list_of_data[2]);
        return tuple<std::string, std::string>(list_of_data[1], list_of_data[2]);
    }
    return tuple<std::string, std::string>("Company", "Company");
}
bool validateDepartmentNameFromFile(std::string department_name)
{
    std::regex department_pattern("([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)");
    return std::regex_match(department_name, department_pattern);
}
tuple<std::string, std::string, std::string> extractDepartmentFromFile(std::string department_name)
{
    tuple<std::string, std::string, std::string> result;
    std::regex department_pattern("([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)->([A-Z]{3}[a-z]+)");
    smatch list_of_data;
    if (regex_search(department_name, list_of_data, department_pattern))
    {
        return tuple<std::string, std::string, std::string>(list_of_data[1], list_of_data[2], list_of_data[3]);
    }
    return tuple<std::string, std::string, std::string>("Department", "Department", "Department");
}
// * VALIDATE CORPORATION NAME, COMPANY NAME, DEPARTMENT NAME FROM TERMINAL
bool validateNameFromTerminal(std::string name)
{
    std::regex name_pattern("^[^\\s]{0}([a-zA-Z0-9]+)[^\\s]{0}$");
    return std::regex_match(name, name_pattern);
}

//? VALIDATE OTHER UTILITIES
bool validateFileTxt(std::string filename)
{
    std::regex filename_pattern("^[^\\s](.*).txt$");
    return std::regex_match(filename, filename_pattern);
}

#endif