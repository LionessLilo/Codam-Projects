SRCS="\
../src/input_checks.c \
../utils/ft_split.c \
../utils/lib_utils.c \
tests_main.c \
test_utils.c \
test_argc.c \
test_argv.c \
test_input_checks.c \
"

cc  -ggdb -Wall -Wextra -Werror -Wconversion $SRCS -I../include -o test_philo
./test_philo