#include <SDL2/SDL.h>
#include <UserLib/test.h>
#include <UserLib/Time.h>
#include <vector>
#include <iostream>
#include <chrono>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();
    std::string time_str = "24:20";

    std::cout << parsingTime(time_str) << std::endl;

    Time timeStart(0, 30);
    Time timeEnd(0, 20);
    Time newTime = timeEnd - timeStart;

    std::cout << newTime << std::endl;

    print_hello_world();
    return 0;
}
