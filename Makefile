NAME   = fractol

CC     = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC     = color.c  complex.c  hooks.c  init.c  julia.c  libft_functions.c  utils.c  main.c  mandelbrot.c  parse.c  render.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re