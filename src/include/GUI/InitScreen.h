#ifndef INITSCREEN_H
#define INITSCREEN_H

#include "Preparation.h"
#include "LoadingInputScreen.h"

void outputInitScreenToScreen(SDL_Window *window, SDL_Renderer *renderer, std::string image_background_path, std::string button_image, std::string logo_path)
{
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
    SDL_Surface *buttonSurface = IMG_Load(button_image.c_str());
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
    SDL_Rect buttonRect = {(SCREEN_WIDTH - buttonSurface->w - 180) / 2, (SCREEN_HEIGHT - buttonSurface->h - 100) / 2, buttonSurface->w, buttonSurface->h};

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

        //! LOGO
        //-------------------------------------------------------------------
        // Load the icon image
        SDL_Surface *iconSurface = SDL_LoadBMP(logo_path.c_str());
        if (iconSurface == nullptr)
        {
            std::cout << "Failed to load icon image! SDL Error: " << SDL_GetError() << std::endl;
        }

        // Set the icon
        SDL_SetWindowIcon(window, iconSurface);

        // Free the icon surface
        SDL_FreeSurface(iconSurface);
        //---------------------------------------------------------------------------

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

            // Render new Scrren
            outputLoadingInputScreenToScreen(window, renderer, "Asset/LoadingScreen/MakeCorp.png", "Asset/LoadingScreen/Terminal.png", "Asset/LoadingScreen/Filepath.png");

            quit = true;
        }
        // UPDATE THE screen
        SDL_RenderPresent(renderer);
    }
}

#endif