#ifndef MBPRINT_H
#define MBPRINT_H
#include "mbtexture.h"

class mbPrint
{
    public:
        mbPrint();
        static int settitle( lua_State* L );
        static int setauthor( lua_State* L );
        static int setline( lua_State* L );
        void render( SDL_Renderer* renderer );
        ~mbPrint();

    protected:

    private:
        static const char* title;
        static const char* author;
        static const char* lines[16][3];
};

#endif // MBPRINT_H
