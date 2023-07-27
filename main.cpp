#include <SDL2/SDL.h>
#include <UserLib/test.h>
#include <UserLib/Time.h>
#include <UserLib/Date.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();

    Time timeStart(0, 30);
    Time timeEnd(0, 20);
    Time newTime = timeEnd - timeStart;

    std::cout << newTime << std::endl;

    print_hello_world();
    
    cout << "sdfsdfewrefdsbfdfsefewfsdgdfvwfeqfsefvdfvb" << endl;

    Date d1{"-1/9/2002"};
    cout<<d1<<endl;
    // cout<<t.tm_hour<<endl<<t.tm_mon<<endl<<t.tm_wday<<endl<<t.tm_yday<<endl<<t.tm_year;

    std::string time_str = "20 : 10 ";
    Time time(time_str);
    std::cout << time << std::endl;

    return 0;
 }
