#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <stdio.h>
#include "../mysql.h"
#include "../mysqld_error.h"
#include "../UserLib/Corporation.h"
#include <sstream>

// LOAD DATABASE -> FROM DATABASE -> CREATE CORP, HUMAN -> RETURN CORP
std::string fillOneZero(unsigned short a)
{
    if (a < 10)
    {
        return "0" + to_string(a);
    }
    else
    {
        return to_string(a);
    }
}

std::string dateToString(Date *date)
{ // 2021-01-01
    return to_string(date->getYear()) + "-" + fillOneZero(date->getMonth()) + "-" + fillOneZero(date->getDay());
}

// ADD HUMAN
void addHumanToMySQL(MYSQL *conn, std::string table_name, Human *human_to_load)
{
    std::string string_human_ID = std::to_string(human_to_load->getID());
    std::stringstream query;
    query << "INSERT INTO " << table_name << " VALUES("
          << string_human_ID << ", '"
          << human_to_load->getFullName() << "', '"
          << human_to_load->getWorkPlace() << "', '"
          << human_to_load->getPosition() << "', '"
          << dateToString(human_to_load->getDateOfBirth()) << "', '"
          << human_to_load->getBirthPlace() << "', '"
          << human_to_load->getEmail() << "', '"
          << human_to_load->getPhoneNum() << "', '"
          << dateToString(human_to_load->getFirstDayAtWork()) << "');";

    std::string queryStr = query.str();

    // TURN INTO CONST CHAR*
    // WRITE TO DATABASE
    mysql_query(conn, queryStr.c_str());
}

// UPDATE HUMAN
void updateHumanToMySQL(MYSQL *conn, std::string table_name, Human *human_to_update)
{
    std::string string_human_ID = std::to_string(human_to_update->getID());
    std::stringstream query;
    query << "UPDATE " << table_name << " SET "
          << "name = '" << human_to_update->getFullName() << "', "
          << "work_place = '" << human_to_update->getWorkPlace() << "', "
          << "position = '" << human_to_update->getPosition() << "', "
          << "date_of_birth = '" << dateToString(human_to_update->getDateOfBirth()) << "', "
          << "birth_place = '" << human_to_update->getBirthPlace() << "', "
          << "email = '" << human_to_update->getEmail() << "', "
          << "phone_num = '" << human_to_update->getPhoneNum() << "', "
          << "first_day_at_work = '" << dateToString(human_to_update->getFirstDayAtWork()) << "' "
          << "WHERE ID = '" << string_human_ID << "';";

    std::string queryStr = query.str();

    // TURN INTO CONST CHAR*

    // WRITE TO THE DATABASE
    cout << "result: " << mysql_query(conn, queryStr.c_str()) << endl;

}

// FOR DEBUG PURPOSE, AND SEE EMPLOYEE
void getHumansFromMySQL(MYSQL *conn, string table_name)
{
    std::stringstream squery;
    squery << "SELECT * FROM " << table_name << ";";
    std::string medium = squery.str();

    cout << "result: " << mysql_query(conn, medium.c_str()) << endl;
    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    while (row = mysql_fetch_row(result))
    {
        for (int i = 0; i < num_fields; i++)
        {
            cout << row[i] << " ";
        }
        cout << endl;
    }

    // CLOSE CONN
    mysql_free_result(result);
    mysql_close(conn);
}

// DELETE HUMAN
void deleteHumanFromMySQL(MYSQL *conn, std::string table_name_1, std::string table_name_2, const unsigned short ID_to_delete)
{
    std::string string_human_ID = std::to_string(ID_to_delete);
    std::stringstream query1;
    std::stringstream query2;
    query1 << "DELETE FROM " << table_name_2 << " WHERE ID = " << string_human_ID << ";";
    query2 << "DELETE FROM " << table_name_1 << " WHERE ID = " << string_human_ID << ";";

    std::string queryStr1 = query1.str();
    std::string queryStr2 = query2.str();

    std::cout << queryStr1 << std::endl;
    std::cout << queryStr2 << std::endl;

    // WRITE TO DATABASE
    cout << "result: " << mysql_query(conn, queryStr1.c_str()) << endl;
    cout << "result: " << mysql_query(conn, queryStr2.c_str()) << endl;
}

// ADD DAYS WORK
void addRecordToMySQL(MYSQL *conn, std::string table_record, const unsigned short ID_to_add, Record *record)
{
    std::string string_human_ID = std::to_string(ID_to_add);
    std::stringstream query;
    query << "INSERT INTO " << table_record << " VALUES("
          << string_human_ID << ", '"
          << dateToString(record->getDayWorked()) << "', '"
          << record->getTimeStartWork() << ":00', '"
          << record->getTimeGoHome() << ":00');";

    std::string queryStr = query.str();

    std::cout << queryStr << std::endl;
    cout << "result: " << mysql_query(conn, queryStr.c_str()) << endl;
}

#endif