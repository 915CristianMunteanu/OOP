#!/bin/sh
gcc -g ./DOMAIN/Estate.c ./SERVICE/Controller.c ./REPOSITORY/Repository.c ./UI/UI.c ./main.c -o ./main
valgrind -s --leak-check=full ./main
