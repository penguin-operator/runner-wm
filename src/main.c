#include <string.h>
#include "common.h"

static struct viking_t viking = {
	.window = {
		.x = 320,
		.y = 180,
		.border = {
			.size = 3,
			.color = "ff5f00",
		},
	},
};

int main(int argc, char** argv) {
	if (argc > 1) {
		if (strcmp(argv[1], "help") == 0) {
			printf("Usage: %s [COMMAND] -[FLAGS]\n", argv[0]);
			printf("Commands:\n");
			printf("\thelp - show this message\n");
			printf("Every flag is optional and command-specific.\n");
			return 0;
		}
	}

	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);
	lua_checkstack(lua, 256);

	config_setup(lua);
	luaL_dofile(lua, "cfg/init.lua");
	config_lua(lua, &viking);

	lua_close(lua);
	return 0;
}
