SRC:=$(wildcard src/*.c)
BIN:=runner-wm

$(BIN): $(SRC)
	@gcc $(SRC) -o $(BIN)

clean:
	@rm -fr $(BIN)
