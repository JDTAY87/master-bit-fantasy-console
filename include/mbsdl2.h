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
        static SDL_Renderer* getrenderer();
        SDL_AudioDeviceID getaudiodeviceID();
        ~mbSDL2();

    protected:

    private:
        bool SDL2start();
        bool imagestart();
        bool audiostart();
        bool windowstart();
        bool rendererstart();
        SDL_Window* window;
        static SDL_Renderer* renderer;
        SDL_GameController* controller;
        SDL_AudioDeviceID audiodeviceID;
};

#endif // MBSDL2_H
