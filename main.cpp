#include <SDL2/SDL.h>
#include <UserLib/test.h>
#include <UserLib/Time.h>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();
    Time time(10, 20);

    std::cout << time << std::endl;

    print_hello_world();
    return 0;
}
