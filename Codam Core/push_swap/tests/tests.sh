make re
make clean
clear
cc ./tests/tests.c -L. -l:./push_swap.a -o main
./main "5 8 7"