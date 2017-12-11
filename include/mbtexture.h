#ifndef MBTEXTURE_H
#define MBTEXTURE_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class mbTexture
{
    public:
        mbTexture();
        bool load( SDL_Renderer* renderer, const char* filename );
        SDL_Texture* gettexture();
        ~mbTexture();

    protected:

    private:
        SDL_Texture* texture;
};

#endif // MBTEXTURE_H
