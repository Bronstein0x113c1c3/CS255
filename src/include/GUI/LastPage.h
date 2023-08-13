#ifndef LASTPAGE_H
#define LASTPAGE_H

#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include <iostream>

void outputLastPage(std::string image_background_path, std::string exit_button_image, std::string logo_path)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
    }

    // Pointer to return
    SDL_Window* window = nullptr;

    // Create a window
    window = SDL_CreateWindow("CS255", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

     //! LOGO
    //-------------------------------------------------------------------
    // Load the icon image
    SDL_Surface* iconSurface = SDL_LoadBMP(logo_path.c_str());
    if (iconSurface == nullptr)
    {
        std::cout << "Failed to load icon image! SDL Error: " << SDL_GetError() << std::endl;
    }

    // Set the icon
    SDL_SetWindowIcon(window, iconSurface);

    // Free the icon surface
    SDL_FreeSurface(iconSurface);
    //---------------------------------------------------------------------------

    // Pointer to return
    SDL_Renderer* renderer = nullptr;

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // Load BACKGROUND SURFACE
    SDL_Surface *backgroundSurface = IMG_Load(image_background_path.c_str());
    if (!backgroundSurface)
    {
        std::cerr << "Image loading failed: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // LOAD BUTTON SURFACE
    SDL_Surface *buttonSurface = IMG_Load(exit_button_image.c_str());
    if (!buttonSurface)
    {
        std::cerr << "Button image loading failed: " << IMG_GetError() << std::endl;
        SDL_FreeSurface(backgroundSurface);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // Create a Texture from the image surface
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_Texture *buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);

    // FREE SURFACE
    SDL_FreeSurface(backgroundSurface);
    SDL_FreeSurface(buttonSurface);

    if (!backgroundTexture || !buttonTexture)
    {
        std::cerr << "Texture creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // BUTTON POSITION AND SIZE
    SDL_Rect buttonRect = {(SCREEN_WIDTH - buttonSurface->w - 180) / 2, (SCREEN_HEIGHT - buttonSurface->h + 300) / 2, buttonSurface->w, buttonSurface->h};

    // Event loop
    bool quit = false;
    bool isInitScreen = true;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                exit(0);
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                // CHECK IF the mouse click is within the button's bounds
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                // Check if the mouse click is inside the button
                if (mouseX >= buttonRect.x && mouseX <= buttonRect.x + buttonRect.w &&
                    mouseY >= buttonRect.y && mouseY <= buttonRect.y + buttonRect.h)
                {
                    isInitScreen = false; // Transition to the new screen
                }
            }
        }
        // Clear the renderer
        SDL_RenderClear(renderer);

        if (isInitScreen)
        {
            // Render the button
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
            SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
        }
        else
        {
            // CLEAN UP
            SDL_DestroyTexture(backgroundTexture);
            SDL_DestroyTexture(buttonTexture);

            quit = true;
        }
        // UPDATE THE screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

#endif