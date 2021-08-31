#!/bin/bash

gcc *.c ./linked_list/list.c ./linked_list/list_utils.c ./stack_list/stack_list.c
./a.out
rm a.out