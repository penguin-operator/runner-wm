#include "viking.h"

void config_setup(lua_State* L) {
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
				lua_pushinteger(L, 3);
				lua_settable(L, 5);
				lua_pushliteral(L, "color");
				lua_pushlstring(L, "ff5f00", 6);
				lua_settable(L, 5);
		lua_settable(L, 3);
	lua_settable(L, 1);
	lua_setglobal(L, "viking");
}

void config_lua(lua_State* L) {
	lua_getglobal(L, "viking");
	lua_getfield(L, -1, "window");
	lua_getfield(L, -1, "border");
	lua_getfield(L, -1, "color");
	viking.window.border.color = lua_tostring(L, -1);
	lua_pop(L, 1);
	lua_getfield(L, -1, "size");
	viking.window.border.size = lua_tointeger(L, -1);
	lua_pop(L, 2);
	lua_getfield(L, -1, "x");
	viking.window.x = lua_tointeger(L, -1);
	lua_pop(L, 1);
	lua_getfield(L, -1, "y");
	viking.window.y = lua_tointeger(L, -1);
	lua_pop(L, 3);
}

int main(int argc, char** argv) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_checkstack(L, 256);
	config_setup(L);

	luaL_dofile(L, "cfg/init.lua");
	config_lua(L);

	printf("viking window x: %d y: %d border size: %d color: %s\n", viking.window.x, viking.window.y, viking.window.border.size, viking.window.border.color);

	lua_close(L);
	return 0;
}
