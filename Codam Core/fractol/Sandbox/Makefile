NAME = mlx_sandbox
CC = cc
CFLAGS = -Werror -Wall -Wextra
LIBMLX42 = ./MLX42

SRCS = pixel_math.c
OBJS = $(SRCS:.c=.o)
INCLUDE = -I./MLX42

all: clone_libmlx42 libmlx42 $(NAME)

clone_libmlx42:
	@if [ ! -d "$(LIBMLX42)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX42); \
	fi

libmlx42: clone_libmlx42
	@cmake -B $(LIBMLX42)/build $(LIBMLX42) && cmake --build $(LIBMLX42)/build -j4

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBMLX42)/build/libmlx42.a -ldl -lglfw -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(INCLUDE)

clean:
	@rm -rf $(LIBMLX42)/build
	@rm -f $(OBJS)
    
fclean: clean
	@rm -f $(NAME)
	@rm -f mlx_sandbox.a
    
re: clean all