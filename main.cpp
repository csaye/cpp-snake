#include <SDL2/SDL.h>

#include "renderer.h"
#include "renderer.cpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    renderer.render();
}
