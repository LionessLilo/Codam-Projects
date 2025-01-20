make re
make clean
clear
cc ./tests/initialisation_test.c -L. -l:./push_swap.a -o main
./main "5 8 7"