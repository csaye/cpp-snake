#include <thread>

#include "game.h"
#include "renderer.h"
#include "renderer.cpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int GRID_WIDTH = 8;
const int GRID_HEIGHT = 8;
const int FPS = 4;

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
    for (int col = 0; col < GRID_WIDTH; col++)
    {
        std::vector<Block> column;
        for (int row = 0; row < GRID_HEIGHT; row++) column.push_back(Block::empty);
        board.push_back(column);
    }
}

void Game::startGameLoop()
{
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);

    running = true;
    SDL_Event event;
    Direction direction = Direction::down;
    initializeBoard();
    int x = 0;
    int y = 0;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) gameOver();

            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        direction = Direction::up;
                        break;
                    case SDLK_DOWN:
                        direction = Direction::down;
                        break;
                    case SDLK_LEFT:
                        direction = Direction::left;
                        break;
                    case SDLK_RIGHT:
                        direction = Direction::right;
                        break;
                }
            }
        }

        board[x][y] = Block::empty;

        switch (direction)
        {
            case Direction::up:
                std::cout << "up";
                y = y > 0 ? y - 1 : GRID_HEIGHT - 1;
                break;
            case Direction::down:
            std::cout << "down";
                y = y < GRID_HEIGHT - 1 ? y + 1 : 0;
                break;
            case Direction::left:
                std::cout << "left";
                x = x > 0 ? x - 1 : GRID_WIDTH - 1;
                break;
            case Direction::right:
                std::cout << "right";
                x = x < GRID_WIDTH - 1 ? x + 1 : 0;
                break;
        }

        board[x][y] = Block::snake;

        renderer.render(board);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
    }
}
