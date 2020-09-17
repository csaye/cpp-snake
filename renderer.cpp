#include <SDL2/SDL.h>
#include <iostream>

#include "renderer.h"

Renderer::Renderer(int screenWidth, int screenHeight)
{
    window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderPresent(renderer);

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

Renderer::~Renderer()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::render()
{
    std::cout << "Rendering\n";
}
