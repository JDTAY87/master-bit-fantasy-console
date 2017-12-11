#ifndef MBPRINT_H
#define MBPRINT_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <lua.hpp>

class mbPrint
{
    public:
        mbPrint();
        void setfont( SDL_Texture* fonttexture );
        static int settitle( lua_State* L );
        static int setauthor( lua_State* L );
        static int setline( lua_State* L );
        void render( SDL_Renderer* renderer );
        ~mbPrint();

    protected:

    private:
        static SDL_Texture* font;
        static const char* title;
        static const char* author;
        static const char* lines[16][3];
};

#endif // MBPRINT_H
