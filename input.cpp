#include "input.h"

void Input::startInputLoop(Game *game) const
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) game->gameOver();
        if (event.type == SDL_KEYDOWN) game->gameOver();
        if (event.type == SDL_MOUSEBUTTONDOWN) game->gameOver();
    }
}
