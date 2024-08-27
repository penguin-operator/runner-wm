#include <stdio.h>
#include <lua5.4/lua.h>
#include <lua5.4/lualib.h>
#include <lua5.4/lauxlib.h>

#ifndef CONFIG
#define CONFIG

struct {
    struct {
        uint16_t x;
        uint16_t y;
        struct {
            uint16_t size;
            char* color;
        } border;
    } window;
} config;

void config_default(lua_State* L);
void config_setup(lua_State* L);

#endif
