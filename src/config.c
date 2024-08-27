#include "config.h"

void config_default(lua_State* L) {
    lua_createtable(L, 0, 1);
        lua_pushliteral(L, "window");
        lua_createtable(L, 0, 1);
            lua_pushliteral(L, "x");
            lua_pushinteger(L, 320);
            lua_settable(L, 3);
            lua_pushliteral(L, "y");
            lua_pushinteger(L, 180);
            lua_settable(L, 3);
            lua_pushliteral(L, "border");
            lua_createtable(L, 0, 2);
                lua_pushliteral(L, "size");
                lua_pushinteger(L, 1);
                lua_settable(L, 5);
                lua_pushliteral(L, "color");
                lua_pushlstring(L, "00ff00", 6);
                lua_settable(L, 5);
        lua_settable(L, 3);
    lua_settable(L, 1);
    lua_setglobal(L, "viking");
}

void config_setup(lua_State* L) {
    lua_getglobal(L, "viking");
    lua_getfield(L, -1, "window");
    lua_getfield(L, -1, "border");
    lua_getfield(L, -1, "color");
    config.window.border.color = lua_tostring(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, -1, "size");
    config.window.border.size = lua_tointeger(L, -1);
    lua_pop(L, 2);
}
