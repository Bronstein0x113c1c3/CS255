#include <SDL2/SDL.h> // FOR GUI
#include <mysql.h>    // FOR DATABASE
#include <mysqld_error.h>
#include<bits/stdc++.h>
#include <string>
#include <iostream>
// #include <UserInteractions/UserInteractions.h>

//? DATABASE ATTRIBUTE
const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "Son09074113456";
const int PORT = 3306;

int main(int argc, char *argv[])
{
    //! TO INIT CONNECTION
    MYSQL *conn = NULL;

    //-------------------------------------
    //? CONNECTION
    conn = mysql_init(0);
    if (conn == NULL)
    {
        std::cout << "FAIL" << std::endl;
    }
    else
    {
        if (mysql_real_connect(conn, HOST, USER, PASS, "corporation", PORT, NULL, 0))
        {
            std::cout << "Logged in!" << std::endl;
        }
    }

    return 0;
}
