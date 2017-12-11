#include "mbprint.h"

SDL_Texture* mbPrint::font = NULL;
const char* mbPrint::title = "title not set";
const char* mbPrint::author = "author not set";
const char* mbPrint::lines[16][3];

mbPrint::mbPrint()
{
    for ( int line = 0; line < 16; line++ )
    {
        lines[line][0] = "";
        lines[line][1] = "";
        lines[line][2] = "";
    }
    return;
}

void mbPrint::setfont( SDL_Texture* fonttexture )
{
    font = fonttexture;
    return;
}

extern "C" int mbPrint::settitle( lua_State* L )
{
    int argcount = lua_gettop( L );
    if ( argcount != 1 )
    {
        lua_pushliteral( L, "Wrong number of arguments. One expected." );
        lua_error( L );
    }
    else if ( !lua_isstring( L, 1 ) )
    {
        lua_pushliteral( L, "Wrong argument type. String expected." );
        lua_error( L );
    }
    else
    {
        title = lua_tostring( L, 1 );
    }
    return 0;
}

extern "C" int mbPrint::setauthor( lua_State* L )
{
    int argcount = lua_gettop( L );
    if ( argcount != 1 )
    {
        lua_pushliteral( L, "Wrong number of arguments. One expected." );
        lua_error( L );
    }
    else if ( !lua_isstring( L, 1 ) )
    {
        lua_pushliteral( L, "Wrong argument type. String expected." );
        lua_error( L );
    }
    else
    {
        author = lua_tostring( L, 1 );
    }
    return 0;
}

extern "C" int mbPrint::setline( lua_State* L )
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
    else if ( !lua_isstring( L, 3 ) )
    {
        lua_pushliteral( L, "Wrong argument type. String expected." );
        lua_error( L );
    }
    else
    {
        lines[lua_tointeger( L, 2 )%16][lua_tointeger( L, 1 )%3] = lua_tostring( L, 3 );
    }
    return 0;
}

void mbPrint::render( SDL_Renderer* renderer )
{
    SDL_Rect srcrect;
    srcrect.w = 10;
    srcrect.h = 20;
    SDL_Rect dstrect;
    dstrect.w = 10;
    dstrect.h = 20;
    dstrect.y = 0;
    for ( int linechar = 0; title[linechar] != 0 && linechar < 32; linechar++ )
    {
        dstrect.x = linechar * 10 + 160;
        srcrect.x = title[linechar] % 16 * 10;
        srcrect.y = title[linechar] / 16 * 20 - 40;
        SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
    }
    dstrect.y = 340;
    for ( int linechar = 0; author[linechar] != 0 && linechar < 32; linechar++ )
    {
        dstrect.x = linechar * 10 + 160;
        srcrect.x = author[linechar] % 16 * 10;
        srcrect.y = author[linechar] / 16 * 20 - 40;
        SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
    }
    for ( int line = 0; line < 16; line++ )
    {
        dstrect.y = line * 20 + 20;
        for ( int linechar = 0; lines[line][0][linechar] != 0 && linechar < 14; linechar++ )
        {
            dstrect.x = linechar * 10 + 10;
            srcrect.x = lines[line][0][linechar] % 16 * 10;
            srcrect.y = lines[line][0][linechar] / 16 * 20 - 40;
            SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
        }
        for ( int linechar = 0; lines[line][1][linechar] != 0 && linechar < 32; linechar++ )
        {
            dstrect.x = linechar * 10 + 160;
            srcrect.x = lines[line][1][linechar] % 16 * 10;
            srcrect.y = lines[line][1][linechar] / 16 * 20 - 40;
            SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
        }
        for ( int linechar = 0; lines[line][2][linechar] != 0 && linechar < 14; linechar++ )
        {
            dstrect.x = linechar * 10 + 490;
            srcrect.x = lines[line][2][linechar] % 16 * 10;
            srcrect.y = lines[line][2][linechar] / 16 * 20 - 40;
            SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
        }
    }
    return;
}

mbPrint::~mbPrint()
{
    return;
}
