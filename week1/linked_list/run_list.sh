#!/bin/bash

make
#gcc -g -I./utils list*.c list*.h
gcc -Wall -Wextra -Werror -I./utils/ list.a list_main.c
./a.out
make fclean
rm a.out