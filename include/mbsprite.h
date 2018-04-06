#ifndef MBSPRITE_H
#define MBSPRITE_H
#include "mbtexture.h"

class mbSprite
{
    public:
        mbSprite();
        static int setsprite( lua_State* L );
        static int movesprite( lua_State* L );
        void render( SDL_Renderer* renderer );

    protected:

    private:
        static int sprframe[40];
        static int spritex[40];
        static int spritey[40];
};

#endif // MBSPRITE_H
