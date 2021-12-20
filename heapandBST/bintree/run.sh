#!/bin/bash

# gcc -g3 -fsanitize=address *.c ./traversal/*.c
gcc *.c ./traversal/*.c
./a.out