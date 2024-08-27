#include "viking.h"

int main(int argc, char** argv) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_checkstack(L, 256);
    config_default(L);

    luaL_dofile(L, "cfg/init.lua");
    config_setup(L);

    printf("viking window x: %d y: %d border size: %d color: %s\n", config.window.x, config.window.y, config.window.border.size, config.window.border.color);

    lua_close(L);
    return 0;
}
