#include <thread>

#include "game.h"
#include "renderer.h"
#include "renderer.cpp"
#include "input.h"
#include "input.cpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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
    Input input;
    input.startInputLoop(this);

    while (running)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        renderer.render();
    }
}
