#include "mbsdl2.h"
#include "mblua.h"
#include "mbtexture.h"
#include "mbprint.h"

class mbEngine
{
public:
    bool start( const char* luafile );
    void mainloop();
private:
    void updatescreen();
    mbSDL2 SDL2;
    mbLua lua;
    mbTexture font;
    mbPrint printdata;
};

bool mbEngine::start( const char* luafile )
{
    bool success = true;
    if ( !SDL2.start() ) { success = false; }
    else if ( !font.load( SDL2.getrenderer(), "jfont2.png" ) ) { success = false; }
    else
    {
        printdata.setfont( font.gettexture() );
        lua.start();
        lua.regfunct( "setauthor", &printdata.setauthor );
        lua.regfunct( "settitle", &printdata.settitle );
        lua.regfunct( "setline", &printdata.setline );
        lua.reglib();
        lua.dofile( luafile );
    }
    return success;
}

void mbEngine::mainloop()
{
    bool quit = false;
    bool minimized = false;
    SDL_Event e;
    const Uint8* keyboardstate = NULL;
    int input = 0;
    while ( !quit )
    {
        while ( SDL_PollEvent(&e) )
        {
            input = 0;
            keyboardstate = SDL_GetKeyboardState( NULL );
            input += keyboardstate[SDL_SCANCODE_C];
            input += keyboardstate[SDL_SCANCODE_Z]*2;
            input += keyboardstate[SDL_SCANCODE_UP]*4;
            input += keyboardstate[SDL_SCANCODE_DOWN]*8;
            input += keyboardstate[SDL_SCANCODE_LEFT]*16;
            input += keyboardstate[SDL_SCANCODE_RIGHT]*32;
            if ( e.type == SDL_QUIT ) { quit = true; }
            if ( e.window.event == SDL_WINDOWEVENT_MINIMIZED ) { minimized = true; }
            if ( e.window.event == SDL_WINDOWEVENT_RESTORED ) { minimized = false; }
        }
        lua.doloop( input );
        if ( minimized == false ) { mbEngine::updatescreen(); }
        else { SDL_Delay(1); }
    }
    return;
}

void mbEngine::updatescreen()
{
    SDL_Renderer* renderer = SDL2.getrenderer();
    SDL_RenderClear( renderer );
    printdata.render( renderer );
    SDL_RenderPresent( renderer );
    return;
}

int main( int argc, char* argv[] )
{
    const char* filename;
    if ( argc == 2 ) { filename = argv[1]; }
    else { filename = "test.lua"; }
    mbEngine engine;
    if ( !engine.start( filename ) ) { printf( "Failed to initialize." ); }
    else { engine.mainloop(); }
    return 0;
}
