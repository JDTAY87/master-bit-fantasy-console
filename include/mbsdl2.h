#ifndef MBSDL2_H
#define MBSDL2_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class mbSDL2
{
    public:
        mbSDL2();
        bool start();
        SDL_Window* getwindow();
        SDL_Renderer* getrenderer();
        ~mbSDL2();

    protected:

    private:
        bool SDL2start();
        bool imagestart();
        bool audiostart();
        bool windowstart();
        bool rendererstart();
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_GameController* controller;
};

#endif // MBSDL2_H
