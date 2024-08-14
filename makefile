SRC:=$(wildcard src/*.c)
BIN:=rwm

$(BIN): $(SRC)
	@gcc $(SRC) -o $(BIN)

clean:
	@rm -fr $(BIN)
