#include "mbtexture.h"

mbTexture::mbTexture()
{
    return;
}

bool mbTexture::load( SDL_Renderer* renderer, const char* filename )
{
    bool success = true;
    texture = IMG_LoadTexture( renderer, filename );
    if ( texture == NULL )
    {
        printf( "IMG_LoadTexture error: %s\n", SDL_GetError() );
        success = false;
    }
    return success;
}

SDL_Texture* mbTexture::gettexture()
{
    return texture;
}

mbTexture::~mbTexture()
{
    SDL_DestroyTexture( texture );
    return;
}
