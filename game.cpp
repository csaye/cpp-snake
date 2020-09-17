#include <thread>
#include <queue>

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

int Game::getPseudoRandom()
{
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    return ms.count() * -1;
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

void Game::spawnFood()
{
    int x = getPseudoRandom() % GRID_WIDTH;
    int y = getPseudoRandom() % GRID_HEIGHT;
    
    while (board[x][y] != Block::empty)
    {
        x = getPseudoRandom() % GRID_WIDTH;
        y = getPseudoRandom() % GRID_HEIGHT;
    }

    board[x][y] = Block::food;
}

void Game::startGameLoop()
{
    Renderer renderer(this, SCREEN_WIDTH, SCREEN_HEIGHT);

    running = true;
    SDL_Event event;
    Direction direction = Direction::down;
    initializeBoard();
    
    std::queue<Position> snakePositions;
    board[0][0] = Block::snake;
    Position head(0, 0);
    snakePositions.push(head);
    spawnFood();

    int x = 0;
    int y = 0;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = false;

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

        switch (direction)
        {
            case Direction::up:
                y = y > 0 ? y - 1 : GRID_HEIGHT - 1;
                break;
            case Direction::down:
                y = y < GRID_HEIGHT - 1 ? y + 1 : 0;
                break;
            case Direction::left:
                x = x > 0 ? x - 1 : GRID_WIDTH - 1;
                break;
            case Direction::right:
                x = x < GRID_WIDTH - 1 ? x + 1 : 0;
                break;
        }

        switch (board[x][y])
        {
            case Block::empty:
            {
                Position tail = snakePositions.front();
                board[tail.x][tail.y] = Block::empty;
                snakePositions.pop();
                Position head(x, y);
                board[x][y] = Block::snake;
                snakePositions.push(head);
                break;
            }
            case Block::snake:
            {
                running = false;
                break;
            }
            case Block::food:
            {
                score++;
                Position head(x, y);
                board[x][y] = Block::snake;
                snakePositions.push(head);
                spawnFood();
                break;
            }
        }

        renderer.render(board);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
    }
}
