#!/bin/sh
BIN=viking
LIB=(lua5.4)
OLD_PS1=$PS1
PS1="(devenv.sh) $OLD_PS1"

build () {
	rm -fr $BIN
	gcc src/*.c -o $BIN `for i in ${LIB}; do echo "-l$i"; done`
}

run () {
	./$BIN $@
}

envexit () {
	PS1=$OLD_PS1
	unset BIN OLD_PS1 LIB
	unset -f build run envexit envreset
}

envreset () {
	envexit
	. devenv.sh
}
