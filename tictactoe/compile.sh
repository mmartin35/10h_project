#!/bin/sh
clear
output1="tictactoe.tty"
output2="tictactoe.graphical"
flags="-std=c11 -Wall -Wextra -Wpedantic -g"
flags_GUI="-lcsfml-graphics -lcsfml-window"
gcc ./src/tty_version.c $flags -o $output1
gcc ./src/main.c ./src/graphics/*.c $flags $flags_GUI -o $output2
