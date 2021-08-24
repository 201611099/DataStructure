#!/bin/bash

#gcc -I../../week1/utils ../../week1/arr_mentor/array.c ../../week1/arr_mentor/array.h stack_arr.c stack_arr_main.c; ./a.out

#rm a.out ../../week1/arr_mentor/*.gch

make
./stack_arr
make fclean