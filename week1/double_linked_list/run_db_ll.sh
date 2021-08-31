#!/bin/bash

make
gcc *.c *.a
./a.out
make fclean
rm a.out