#include <SDL2/SDL.h>
#include <mysql.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

const char HOST[] = "127.0.0.1";
const char USER[] = "root";
const char PASS[] = "Son09074113456";
const unsigned short PORT = 3306;

int main(int argc, char *args[])
{
    MYSQL *conn = mysql_init(nullptr);

    if (conn == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_real_connect(conn, HOST, USER, PASS, "corporation", 3306, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }
    else
    {
        std::cout << "Connect Success!" << std::endl;
    }

    if (mysql_query(conn, "CREATE DATABASE testdb"))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    return 0;
}