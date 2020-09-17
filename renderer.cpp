#include <iostream>
#include <SDL2/SDL.h>

#include "renderer.h"

Renderer::Renderer(Game *game_, int screenWidth, int screenHeight)
{
    game = game_;
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer()
{
    std::cout << "You died.\n";
    std::cout << "Your final score was " << game->getScore() << ".\n";
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::clear() const
{
    SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
    SDL_RenderClear(renderer);
}

void Renderer::drawBox(int col, int row, int r, int g, int b) const
{
    SDL_Rect block;
    block.w = 100;
    block.h = 100;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    block.x = col * block.w;
    block.y = row * block.h;
    SDL_RenderFillRect(renderer, &block);
}

void Renderer::render(std::vector<std::vector<Game::Block>> &board) const
{
    clear();

    for (int col = 0; col < board.size(); col++)
    {
        for (int row = 0; row < board[col].size(); row++)
        {
            switch (board[col][row])
            {
                case Game::Block::empty:
                    break;
                case Game::Block::snake:
                    drawBox(col, row, 0, 255, 0);
                    break;
                case Game::Block::food:
                    drawBox(col, row, 255, 0, 0);
                    break;
            }
        }
    }

    SDL_RenderPresent(renderer);
}
