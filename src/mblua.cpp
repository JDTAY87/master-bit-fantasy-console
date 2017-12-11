#include "mblua.h"

mbLua::mbLua()
{
    functcount = 0;
    return;
}

void mbLua::start()
{
    L = luaL_newstate();
    return;
}

void mbLua::regfunct( const char* functname, lua_CFunction funct )
{
    if (functcount < 80)
    {
        mbitlib[functcount].name = functname;
        mbitlib[functcount].func = funct;
        functcount++;
        mbitlib[functcount].name = NULL;
        mbitlib[functcount].func = NULL;
    }
    return;
}

void mbLua::reglib()
{
    luaL_newlib( L, mbitlib );
    lua_setglobal( L, "mbit" );
    return;
}

void mbLua::dofile( const char* filename )
{
    luaL_dofile( L, filename );
    lua_getglobal( L, "mbitSettings" );
    lua_pcall( L, 0, 0, 0 );
    return;
}

void mbLua::doloop( int input )
{
    lua_getglobal( L, "mbitLoop" );
    lua_pushinteger( L, input );
    lua_pcall( L, 1, 0, 0 );
    return;
}

mbLua::~mbLua()
{
    lua_close( L );
    return;
}
