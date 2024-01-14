#!/bin/bash
<<<<<<< HEAD
gcc -c *.c
ar rc liball.a *.o
gcc -Wall -pedantic -Werror -Wextra -c *.c
ar -rc liball.a *.o
ar -t liball.a
ranlib liball.a

