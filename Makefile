NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra -O3
CFLAGS += -I./include/

MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a

SRC =	./src/main.c
SRC +=	./src/display2D.c 
SRC +=	./src/event.c 
SRC +=	./src/raycasting.c
SRC +=	./src/raycasting_tools.c
SRC +=	./src/check_arg.c 
SRC +=	./src/check_map.c 
SRC +=	./src/clear_exit.c
SRC +=	./src/create_map.c 
SRC +=	./src/create_tab.c 
SRC +=	./src/ft_check_color.c 
SRC +=	./src/ft_check_empty.c
SRC +=	./src/ft_isspace.c 
SRC +=	./src/read_file.c 
SRC +=	./src/setup_data.c
SRC +=	./src/setup_game.c 
SRC +=	./src/setup_path_color.c 
SRC +=	./src/ft_isstart.c 
SRC +=	./src/ft_strdup_max.c
SRC +=	./src/ft_strcmp.c 
SRC +=	./src/exit_game.c 
SRC +=	./src/start_game.c
SRC +=	./src/pixel.c

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

