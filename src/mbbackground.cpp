#include "mbbackground.h"

int mbBackground::tiles[256];

mbBackground::mbBackground()
{
    for ( int z = 0; z < 256; z++ )
    {
        tiles[z] = 0;
    }
}

extern "C" int mbBackground::settile( lua_State* L )
{
    int argcount = lua_gettop( L );
    if ( argcount != 2 )
    {
        lua_pushliteral( L, "Wrong number of arguments. Two expected." );
        lua_error( L );
    }
    else if ( !lua_isinteger( L, 1 ) )
    {
        lua_pushliteral( L, "Wrong argument type. Integer expected." );
        lua_error( L );
    }
    else if ( !lua_isinteger( L, 2 ) )
    {
        lua_pushliteral( L, "Wrong argument type. Integer expected." );
        lua_error( L );
    }
    else
    {
        tiles[ lua_tointeger( L, 1 ) % 256 ] = lua_tointeger( L, 2 ) % 256;
    }
    return 0;
}

void mbBackground::render( SDL_Renderer* renderer )
{
    SDL_Rect srcrect;
    srcrect.w = 20;
    srcrect.h = 20;
    SDL_Rect dstrect;
    dstrect.w = 20;
    dstrect.h = 20;
    for ( int z = 0; z < 256; z++ )
    {
        srcrect.x = tiles[z] % 16 * 20;
        srcrect.y = tiles[z] / 16 * 20;
        dstrect.x = z % 16 * 20 + 160;
        dstrect.y = z / 16 * 20 + 20;
        SDL_RenderCopy( renderer, mbTexture::gettiles(), &srcrect, &dstrect );
    }
}
