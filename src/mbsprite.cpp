#include "mbsprite.h"

int mbSprite::sprframe[40];
int mbSprite::spritex[40];
int mbSprite::spritey[40];

mbSprite::mbSprite()
{
    for ( int z = 0; z < 40; z++ )
    {
        sprframe[z] = 0;
        spritex[z] = 0;
        spritey[z] = 0;
    }
}

extern "C" int mbSprite::setsprite( lua_State* L )
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
        sprframe[ lua_tointeger( L, 1 ) % 40 ] = lua_tointeger( L, 2 ) % 256;
    }
    return 0;
}

extern "C" int mbSprite::movesprite( lua_State* L )
{
    int argcount = lua_gettop( L );
    if ( argcount != 3 )
    {
        lua_pushliteral( L, "Wrong number of arguments. Three expected." );
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
    else if ( !lua_isinteger( L, 3 ) )
    {
        lua_pushliteral( L, "Wrong argument type. Integer expected." );
        lua_error( L );
    }
    else
    {
        spritex[ lua_tointeger( L, 1 ) % 40 ] = lua_tointeger( L, 2 ) % 300;
        spritey[ lua_tointeger( L, 1 ) % 40 ] = lua_tointeger( L, 3 ) % 300;
    }
    return 0;
}

void mbSprite::render( SDL_Renderer* renderer )
{
    SDL_Rect srcrect;
    srcrect.w = 20;
    srcrect.h = 20;
    SDL_Rect dstrect;
    dstrect.w = 20;
    dstrect.h = 20;
    for ( int z = 0; z < 40; z++ )
    {
        srcrect.x = sprframe[z] % 16 * 20;
        srcrect.y = sprframe[z] / 16 * 20;
        dstrect.x = spritex[z] + 160;
        dstrect.y = spritey[z] + 20;
        SDL_RenderCopy( renderer, mbTexture::getsprites(), &srcrect, &dstrect );
    }
}
