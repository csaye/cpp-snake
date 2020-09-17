#ifndef GAME_H
#define GAME_H

class Game
{
    public:
        Game();
        void gameOver();
    private:
        void startGameLoop();
        bool running;
};

#endif