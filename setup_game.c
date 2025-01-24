/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:16:36 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/21 16:39:22 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_data(t_game *game)
{
	game->data.tab = NULL;
	game->data.map = NULL;
	game->data.line = NULL;
	game->data.no_path = NULL;
	game->data.so_path = NULL;
	game->data.we_path = NULL;
	game->data.ea_path = NULL;
	game->data.c_clr = 0;
	game->data.f_clr = 0;
	game->data.no_nb = 0;
	game->data.so_nb = 0;
	game->data.we_nb = 0;
	game->data.ea_nb = 0;
	game->data.c_nb = 0;
	game->data.f_nb = 0;
}
void init_player(t_player *player, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'E' )
			{
				player->pos_x = x;
				player->pos_y = y;
				player->dir[0] = -1;
				player->dir[1] = 0;
				player->dir_plane[0] = 0;
				player->dir_plane[1] = -0.60;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	setup_game(char *file)
{
	t_game	game;
	t_frame	frame;
	t_player player;
	int		width;
	int		height;

	if (!ft_check_arg(file))
		ft_exit_err(file, " is not a correct file\n", 1);
	ft_init_data(&game);
	if (!ft_read_file(&game, file))
		ft_exit_err(NULL, "Can't read file\n", 1);
	if (!ft_create_tab(&game))
		ft_exit_err(NULL, "Malloc error\n", 1);
	if (!ft_setup_data(&game))
		ft_clear_parse(&game, "Wrong format in file\n");
	// On commence ici a call la fonction qui va gerer minilibx et generer notre "jeu"
	width = 500;
	height = 500;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, width, height, "cub3D");
	init_player(&player, game.data.map);
	frame.img = mlx_new_image(game.mlx, width, height);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length, &frame.endian);
	//display_frame(player, vars.map, frame, vars);
	mlx_loop(game.mlx);
	// pour l'instant, on affiche juste les path, colors et la map
	//i = 0;
	//while (game.data.map[i])
	//	printf("%s\n", game.data.map[i++]);
	//printf("%s\n", game.data.no_path);
	//printf("%s\n", game.data.so_path);
	//printf("%s\n", game.data.we_path);
	//printf("%s\n", game.data.ea_path);
	//printf("%d\n", game.data.f_clr);
	//printf("%d\n", game.data.c_clr);
	//ft_clear_all(&game, NULL);
	//exit(0);
}
