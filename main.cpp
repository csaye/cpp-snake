#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
// #include <thread>
// #include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize!\n";
    }
    else
    {
        window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created!\n";
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            
            SDL_Event e;
            bool quit = false;
            while (!quit)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT) quit = true;
                    if (e.type == SDL_KEYDOWN) quit = true;
                    if (e.type == SDL_MOUSEBUTTONDOWN) quit = true;
                }
            }
        }
        
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    // SDL_Window *sdl_window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, SDL_WINDOW_SHOWN);
    // SDL_Renderer *sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

    // SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    // SDL_RenderClear(sdl_renderer);
    // SDL_RenderPresent(sdl_renderer);
    // std::this_thread::sleep_for(std::chrono::seconds(3));
}
