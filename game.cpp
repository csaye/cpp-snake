#include <vector>
#include <thread>

#include "game.h"
#include "renderer.h"
#include "renderer.cpp"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int FPS = 10;

Game::Game()
{
    startGameLoop();
}

void Game::gameOver()
{
    running = false;
}

void Game::initializeBoard()
{
    for (int col = 0; col < SCREEN_WIDTH; col += 100)
    {
        std::vector<int> column;
        for (int row = 0; row < SCREEN_HEIGHT; row += 100) column.push_back(0);
        board.push_back(column);
    }
}

void Game::startGameLoop()
{
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);

    running = true;
    SDL_Event event;
    Direction direction;
    initializeBoard();

    while (running)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) gameOver();

            if (event.type == SDLK_UP) direction = Direction::up;
            if (event.type == SDLK_DOWN) direction = Direction::down;
            if (event.type == SDLK_LEFT) direction = Direction::left;
            if (event.type == SDLK_RIGHT) direction = Direction::right;
        }

        renderer.render();
    }
}
