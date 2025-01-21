make re
make clean
clear
cc ./tests/init_tests.c -L. -l:./push_swap.a -o init_main
./init_main "5 8 7"