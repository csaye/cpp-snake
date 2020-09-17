// #include <iostream>
#include <SDL2/SDL.h>
// #include <stdio.h>

#include "renderer.h"
#include "renderer.cpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    renderer.render();

    // SDL_Window *window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // SDL_RenderPresent(renderer);

    // SDL_Event e;
    // bool quit = false;
    // while (!quit)
    // {
    //     while (SDL_PollEvent(&e))
    //     {
    //         if (e.type == SDL_QUIT) quit = true;
    //         if (e.type == SDL_KEYDOWN) quit = true;
    //         if (e.type == SDL_MOUSEBUTTONDOWN) quit = true;
    //     }
    // }

    // SDL_DestroyWindow(window);
    // SDL_Quit();
}
