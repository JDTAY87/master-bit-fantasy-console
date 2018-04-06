#ifndef MBTEXTURE_H
#define MBTEXTURE_H
#include "mbsdl2.h"
#include <lua.hpp>

class mbTexture
{
    public:
        mbTexture();
        bool loadfont( const char* filename );
        static int loadtiles( lua_State* L );
        static int loadsprites( lua_State* L );
        static SDL_Texture* getfont();
        static SDL_Texture* gettiles();
        static SDL_Texture* getsprites();
        ~mbTexture();

    protected:

    private:
        static SDL_Texture* font;
        static SDL_Texture* tiles;
        static SDL_Texture* sprites;
};

#endif // MBTEXTURE_H
