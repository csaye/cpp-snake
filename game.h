#ifndef GAME_H
#define GAME_H

#include <vector>

class Game
{
    public:
        Game();
        void gameOver();
        enum class Direction { up, down, left, right };
    private:
        void initializeBoard();
        void startGameLoop();
        bool running;
        std::vector<std::vector<int>> board;
};

#endif