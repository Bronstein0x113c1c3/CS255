#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include "../mysql.h"
#include "../mysqld_error.h"

MYSQL* init()
{
    // MYSQL CONNECTION
    MYSQL *conn = nullptr;

    conn = mysql_init(nullptr);

    if (conn == nullptr)
    {
        std::cerr << mysql_error(conn) << std::endl;
    }

    return conn;
}

MYSQL* connectToDB(MYSQL* initialized_conn ,char HOST[], char USER[], char PASS[], char DATABASE[], unsigned short PORT)
{
    // SET FLAG
    bool success = true;

    if (mysql_real_connect(initialized_conn, HOST, USER, PASS, DATABASE, PORT, NULL, 0) == NULL)
    {
        std::cerr << mysql_error(initialized_conn) << std::endl;
        mysql_close(initialized_conn);
        success = false;
    }
    else
    {
        printf("Connect Success!\n");
    }

    return initialized_conn;
}

#endif