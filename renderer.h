#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
    public:
        Renderer(int screenWidth, int screenHeight);
        ~Renderer();
        void render(std::vector<std::vector<int>> &board) const;
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        void clear() const;
        void drawBox(int col, int row) const;
};

#endif