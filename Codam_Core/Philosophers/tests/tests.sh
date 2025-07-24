SRCS="\
../src/input_checks.c \
../src/init.c \
../src/cleanup.c \
../utils/ft_split.c \
../utils/lib_utils.c \
../utils/clean_up_utils.c \
tests_main.c \
test_utils.c \
test_argc.c \
test_argv.c \
test_input_checks.c \
test_input_to_whiteboard.c \
test_init_whiteboard_mutexes.c
test_init_philosophers.c"

cc  -ggdb -Wall -Wextra -Werror -Wconversion $SRCS -I../include -o test_philo
./test_philo