#include <stdio.h>
#include <stdint.h>
#include <lua5.4/lua.h>
#include <lua5.4/lualib.h>
#include <lua5.4/lauxlib.h>

#ifndef VIKING
#define VIKING

struct viking_t {
	struct window_t {
		uint16_t x;
		uint16_t y;
		struct border_t {
			uint16_t size;
			char* color;
		} border;
	} window;
};

void config_setup(lua_State*);
void config_lua(lua_State*, struct viking_t*);

#endif
