#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

bool isFilePath = false;
bool isTerminal = false;

void outputLoadingInputScreenToScreen(SDL_Window *window, SDL_Renderer *renderer, std::string image_background_path, std::string button_terminal_image, std::string button_file_path_image)
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
    SDL_Surface *buttonTerminalSurface = IMG_Load(button_terminal_image.c_str());
    SDL_Surface *buttonFilePathSurface = IMG_Load(button_file_path_image.c_str());
    if (!buttonTerminalSurface || !buttonFilePathSurface)
    {
        std::cerr << "Button image loading failed: " << IMG_GetError() << std::endl;
        SDL_FreeSurface(backgroundSurface);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // Create a Texture from the image surface
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_Texture *buttonTerminalTexture = SDL_CreateTextureFromSurface(renderer, buttonTerminalSurface);
    SDL_Texture *buttonFilePathTexture = SDL_CreateTextureFromSurface(renderer, buttonFilePathSurface);

    // FREE SURFACE
    SDL_FreeSurface(backgroundSurface);
    SDL_FreeSurface(buttonTerminalSurface);
    SDL_FreeSurface(buttonFilePathSurface);

    if (!backgroundTexture || !buttonFilePathTexture || !buttonTerminalTexture)
    {
        std::cerr << "Texture creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // BUTTON POSITION AND SIZE
    SDL_Rect buttonFilePathRect = {(SCREEN_WIDTH - buttonFilePathSurface->w + 200) / 2, (SCREEN_HEIGHT - buttonFilePathSurface->h - 100) / 2, buttonFilePathSurface->w, buttonFilePathSurface->h};
    SDL_Rect buttonTerminalRect = {(SCREEN_WIDTH - buttonTerminalSurface->w - 400) / 2, (SCREEN_HEIGHT - buttonTerminalSurface->h - 100) / 2, buttonTerminalSurface->w, buttonTerminalSurface->h};

    bool quit = false;
    bool isLoadingScreen = true;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                exit(0); // QUIT THE PROGRAM
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) // Terminal Part
            {
                // CHECK IF the mouse click is within the button's bounds
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                // Check if the mouse click is inside the TerminalButton
                if (mouseX >= buttonTerminalRect.x && mouseX <= buttonTerminalRect.x + buttonTerminalRect.w &&
                    mouseY >= buttonTerminalRect.y && mouseY <= buttonTerminalRect.y + buttonFilePathRect.h)
                {
                    isLoadingScreen = false; // Transition to the new screen
                    isTerminal = true;
                }

                // CHECK IF the mouse click is inside the FilePathbutton
                else if (mouseX >= buttonFilePathRect.x && mouseX <= buttonFilePathRect.x + buttonFilePathRect.w &&
                         mouseY >= buttonFilePathRect.y && mouseY <= buttonFilePathRect.y + buttonFilePathRect.h)
                {
                    isLoadingScreen = false; // Transition to the new screen
                    isFilePath = true;
                }
            }
        }
        // Clear the renderer
        SDL_RenderClear(renderer);

        if (isLoadingScreen)
        {
            // Render the button
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
            SDL_RenderCopy(renderer, buttonTerminalTexture, NULL, &buttonTerminalRect);
            SDL_RenderCopy(renderer, buttonFilePathTexture, NULL, &buttonFilePathRect);
        }
        else if (isTerminal) //! THE USER WILL TURN INTO TERMINAL AFTTER THEY CHOOSE FILEPATH OR TERMINAL
        {
            // CLEAN UP
            SDL_DestroyTexture(backgroundTexture);
            SDL_DestroyTexture(buttonFilePathTexture);
            SDL_DestroyTexture(buttonFilePathTexture);
            
            // CLEAN UP SDL
            quit = true;
        }
        else if (isFilePath)
        {
            // CLEAN UP
            SDL_DestroyTexture(backgroundTexture);
            SDL_DestroyTexture(buttonFilePathTexture);
            SDL_DestroyTexture(buttonFilePathTexture);

            // CLEAN UP SDL
            quit = true;
        }

        // UPDATE THE SCREEN
        SDL_RenderPresent(renderer);
    }
}

#endif