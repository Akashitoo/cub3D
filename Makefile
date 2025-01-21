NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra -O3

MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a

SRC = main.c display2D.c event.c raycasting.c\

OBJS = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(MAKE) --no-print-directory -C ./libft
	$(MAKE) --no-print-directory -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
