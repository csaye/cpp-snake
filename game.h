#ifndef GAME_H
#define GAME_H

#include <vector>

class Game
{
    public:
        Game();
        void gameOver();
        enum class Direction { up, down, left, right };
        enum class Block { empty, snake, food };
    private:
        int getPseudoRandom();
        void initializeBoard();
        void spawnFood();
        void startGameLoop();
        bool running;
        std::vector<std::vector<Block>> board;
};

#endif