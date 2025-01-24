NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra -O3

MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a

SRC = main.c display2D.c event.c raycasting.c \
		check_arg.c check_map.c clear_exit.c create_map.c \
		create_tab.c ft_check_color.c ft_check_empty.c ft_isspace.c \
		read_file.c setup_data.c setup_game.c setup_path_color.c \
		ft_isstart.c ft_strdup_max.c ft_strcmp.c \

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
