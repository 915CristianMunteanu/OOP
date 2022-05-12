#!/bin/sh
gcc -g ./Movie.cpp ./DynamicVector.cpp ./Repository.cpp ./Service.cpp ./UI.cpp ./main.cpp -o ./main
valgrind -s --leak-check=full ./main
