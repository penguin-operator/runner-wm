#include <stdio.h>
#include <stdint.h>
#include <lua5.4/lua.h>
#include <lua5.4/lualib.h>
#include <lua5.4/lauxlib.h>

#ifndef VIKING
#define VIKING

struct {
	struct {
		uint16_t x;
		uint16_t y;
		struct {
			uint16_t size;
			char* color;
		} border;
	} window;
} viking;

void config_setup(lua_State* L);
void config_lua(lua_State* L);

#endif
