#include "mbsdl2.h"

mbSDL2::mbSDL2()
{
    return;
}

bool mbSDL2::start()
{
    bool success = true;
    if ( !mbSDL2::SDL2start() ) { success = false; }
    else if ( !mbSDL2::imagestart() ) { success = false; }
    else if ( !mbSDL2::audiostart() ) { success = false; }
    else if ( !mbSDL2::windowstart() ) { success = false; }
    else if ( !mbSDL2::rendererstart() ) { success = false; }
    return success;
}

bool mbSDL2::SDL2start()
{
    bool success = true;
    if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_GAMECONTROLLER) < 0 )
    {
        printf( "SDL_Init error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        controller = SDL_GameControllerOpen( 0 );
    }
    return success;
}

bool mbSDL2::imagestart()
{
    bool success = true;
    if ( (IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG) != IMG_INIT_PNG )
    {
        printf( "IMG_Init error: %s\n", SDL_GetError() );
        success = false;
    }
    return success;
}

bool mbSDL2::audiostart()
{
    bool success = true;
    SDL_AudioSpec wantspec;
    SDL_zero( wantspec );
    wantspec.freq = 22050;
    wantspec.format = AUDIO_U8;
    wantspec.channels = 1;
    wantspec.samples = 4;
    wantspec.callback = NULL;
    if ( SDL_OpenAudio( &wantspec, NULL ) < 0 )
    {
        printf( "SDL_OpenAudio error: %s\n", SDL_GetError() );
        success = false;
    }
    return success;
}

bool mbSDL2::windowstart()
{
    bool success = true;
    window = SDL_CreateWindow( "Master-Bit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_RESIZABLE );
    if ( window == NULL )
    {
        printf( "SDL_CreateWindow error: %s\n", SDL_GetError() );
        success = false;
    }
    return success;
}

bool mbSDL2::rendererstart()
{
    bool success = true;
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC );
    if ( renderer == NULL )
    {
        printf( "SDL_CreateRenderer error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        SDL_RenderSetLogicalSize( renderer, 640, 360 );
        SDL_RenderSetIntegerScale( renderer, SDL_TRUE );
        SDL_SetRenderDrawColor( renderer, 204, 153, 51, 255 );
    }
    return success;
}

SDL_Window* mbSDL2::getwindow()
{
    return window;
}

SDL_Renderer* mbSDL2::getrenderer()
{
    return renderer;
}

mbSDL2::~mbSDL2()
{
    SDL_GameControllerClose( controller );
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    SDL_CloseAudio();
    IMG_Quit();
    SDL_Quit();
    return;
}
