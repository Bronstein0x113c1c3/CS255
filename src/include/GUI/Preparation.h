#ifndef PREPARATION_H
#define PREPARATTION_H

#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include <iostream>

// Define screen dimensions
const int SCREEN_WIDTH = 972;
const int SCREEN_HEIGHT = 546;

bool initSDL()
{
    // SET FLAG
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        success = false;
    }
    return success;
}

SDL_Window* createWindow(std::string screen_title)
{
    // Pointer to return
    SDL_Window* window = nullptr;

    // Create a window
    window = SDL_CreateWindow(screen_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window_to_render)
{
    // Pointer to return
    SDL_Renderer* renderer = nullptr;

    // Create a renderer
    renderer = SDL_CreateRenderer(window_to_render, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window_to_render);
        SDL_Quit();
    }

    return renderer;
}

void cleanUpSDL( SDL_Window* window_to_destroy, SDL_Renderer* renderer_to_destroy)
{
    // Clean up and quit SDL
    SDL_DestroyRenderer(renderer_to_destroy);
    SDL_DestroyWindow(window_to_destroy);
    SDL_Quit();
}

#endif