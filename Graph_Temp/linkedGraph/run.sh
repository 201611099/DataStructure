#!/bin/bash

gcc -g3 -fsanitize=address *.c ./linked_list/*.c
#gcc *.c ./linked_list/*.c
./a.out