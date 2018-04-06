#ifndef MBBACKGROUND_H
#define MBBACKGROUND_H
#include "mbtexture.h"

class mbBackground
{
    public:
        mbBackground();
        static int settile( lua_State* L );
        void render( SDL_Renderer* renderer );

    protected:

    private:
        static int tiles[256];
};

#endif // MBBACKGROUND_H
