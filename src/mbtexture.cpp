#include "mbtexture.h"

SDL_Texture* mbTexture::font = NULL;
SDL_Texture* mbTexture::tiles = NULL;
SDL_Texture* mbTexture::sprites = NULL;

mbTexture::mbTexture()
{
    return;
}

bool mbTexture::loadfont( const char* filename )
{
    bool success = true;
    font = IMG_LoadTexture( mbSDL2::getrenderer(), filename );
    if ( font == NULL )
    {
        printf( "IMG_LoadTexture error: %s\n", SDL_GetError() );
        success = false;
    }
    return success;
}

extern "C" int mbTexture::loadtiles( lua_State* L )
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
        const char* filename = lua_tostring( L, 1 );
        SDL_Surface* tilessurface = IMG_Load( filename );
        SDL_Palette* tilespalette = SDL_AllocPalette( 2 );
        SDL_Color tilescolors[2] = { { 204, 153, 51, 255 }, { 0, 0, 0, 255 } };
        SDL_SetPaletteColors( tilespalette, &tilescolors[0], 0, 2 );
        SDL_SetPixelFormatPalette( tilessurface->format, tilespalette );
        tiles = SDL_CreateTextureFromSurface( mbSDL2::getrenderer(), tilessurface );
        SDL_FreePalette( tilespalette );
        SDL_FreeSurface( tilessurface );
    }
    return 0;
}

extern "C" int mbTexture::loadsprites( lua_State* L )
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
        const char* filename = lua_tostring( L, 1 );
        SDL_Surface* spritessurface = IMG_Load( filename );
        SDL_Palette* spritespalette = SDL_AllocPalette( 2 );
        SDL_Color spritescolors[2] = { { 204, 153, 51, 0 }, { 0, 0, 0, 255 } };
        SDL_SetPaletteColors( spritespalette, &spritescolors[0], 0, 2 );
        SDL_SetPixelFormatPalette( spritessurface->format, spritespalette );
        sprites = SDL_CreateTextureFromSurface( mbSDL2::getrenderer(), spritessurface );
        SDL_FreePalette( spritespalette );
        SDL_FreeSurface( spritessurface );
    }
    return 0;
}

SDL_Texture* mbTexture::getfont()
{
    return font;
}

SDL_Texture* mbTexture::gettiles()
{
    return tiles;
}

SDL_Texture* mbTexture::getsprites()
{
    return sprites;
}

mbTexture::~mbTexture()
{
    SDL_DestroyTexture( sprites );
    SDL_DestroyTexture( tiles );
    SDL_DestroyTexture( font );
    return;
}
