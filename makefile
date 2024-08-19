SRC:=$(wildcard src/*.c)
BIN:=run-de

$(BIN): $(SRC)
	@gcc $(SRC) -o $(BIN)

clean:
	@rm -fr $(BIN)
