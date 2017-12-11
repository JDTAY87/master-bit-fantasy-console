#ifndef MBLUA_H
#define MBLUA_H
#include <lua.hpp>

class mbLua
{
    public:
        mbLua();
        void start();
        void regfunct( const char* functname, lua_CFunction funct );
        void reglib();
        void dofile( const char* filename );
        void doloop( int input );
        ~mbLua();

    protected:

    private:
        lua_State* L;
        luaL_Reg mbitlib[80];
        int functcount;
};

#endif // MBLUA_H
