#include <SDL2/SDL.h>
#include <iostream>

#include "renderer.h"

void Renderer::render()
{
    std::cout << "Rendering\n";
}

Renderer::~Renderer()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}
