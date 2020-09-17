#include <SDL2/SDL.h>
#include <iostream>

#include "renderer.h"

Renderer::Renderer(int screenWidth, int screenHeight)
{
    window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::clear() const
{
    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);
}

void Renderer::drawBox(int col, int row) const
{
    SDL_Rect block;
    block.w = 100;
    block.h = 100;
    SDL_SetRenderDrawColor(renderer, 0x00, 0x7A, 0xCC, 0xFF);
    block.x = col * block.w;
    block.y = row * block.h;
    SDL_RenderFillRect(renderer, &block);
}

void Renderer::render(std::vector<std::vector<int>> &board) const
{
    std::cout << "Rendering\n";
    clear();

    for (int col = 0; col < board.size(); col++)
    {
        for (int row = 0; row < board[col].size(); row++)
        {
            if (board[col][row] == 1)
            {
                drawBox(col, row);
            }
        }
    }

    SDL_RenderPresent(renderer);
}
