#include <SDL2/SDL.h>
#include <UserLib/test.h>
#include <UserLib/Time.h>
#include <UserLib/Date.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>


using namespace std;
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();
    Time time(10, 20);

    std::cout << time << std::endl;

    print_hello_world();
    
    cout << "sdfsdfewrefdsbfdfsefewfsdgdfvwfeqfsefvdfvb" << endl;

    Date d1{"-1/9/2002"};
    cout<<d1<<endl;
    // cout<<t.tm_hour<<endl<<t.tm_mon<<endl<<t.tm_wday<<endl<<t.tm_yday<<endl<<t.tm_year;
 }
