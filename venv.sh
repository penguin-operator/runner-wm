#!/bin/sh
BIN=viking
OLD_PS1=$PS1
PS1="(venv.sh) $OLD_PS1"

build () {
    rm -fr $BIN
    gcc src/*.c -o $BIN -llua5.4
}

run () {
    ./$BIN $@
}

envexit () {
    PS1=$OLD_PS1
    unset BIN OLD_PS1
    unset -f build run envexit envreset
}

envreset () {
    envexit
    . venv.sh
}