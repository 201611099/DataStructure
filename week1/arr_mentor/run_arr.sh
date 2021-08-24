#!/bin/bash

make
gcc -Wall -Wextra -Werror -I./utils/ arr.a main.c
./a.out
make fclean
rm a.out