#include <thread>

#include "game.h"
#include "renderer.h"
#include "renderer.cpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 10;

Game::Game()
{
    startGameLoop();
}

void Game::gameOver()
{
    running = false;
}

void Game::startGameLoop()
{
    running = true;
    
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Event event;

    while (running)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) gameOver();
            if (event.type == SDL_KEYDOWN) gameOver();
            if (event.type == SDL_MOUSEBUTTONDOWN) gameOver();
        }
        
        renderer.render();
    }
}
