/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 06:47:10 by mqwa              #+#    #+#             */
/*   Updated: 2025/02/09 03:32:08 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_get_path(t_game *game, int index)
{
	if (index == 0)
		return (game->data.no_p);
	if (index == 1)
		return (game->data.so_p);
	if (index == 2)
		return (game->data.ea_p);
	if (index == 3)
		return (game->data.we_p);
	return (NULL);
}

static void	init_textures(t_game *game)
{
	int		i;
	t_frame	*text;
	char	*path;

	i = -1;
	while (++i < 4)
	{
		text = malloc(sizeof(t_frame));
		if (!text)
			ft_clear_all(game, "Malloc error\n", 1, i);
		path = ft_get_path(game, i);
		if (!path)
			ft_clear_all(game, "Malloc error\n", 1, i);
		text->img = mlx_xpm_file_to_image(game->mlx, path,
				&text->width, &text->height);
		printf("width : %d height : %d\n", text->width, text->height);
		if (!text->img)
		{
			free(text);
			ft_clear_all(game, "MinilibX img error\n", 1, i);
		}		
		text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
				&text->line_length, &text->endian);
		game->textures[i] = text;
	}
}

void	init_dir(t_player *player, char c)
{
	int		sign;

	sign = 1;
	if (c == 'N' || c == 'S')
	{
		if (c == 'N')
			sign = -1;
		player->dir[0] = 0;
		player->dir[1] = 1 * sign;
		player->dir_plane[0] = -0.66 * sign;
		player->dir_plane[1] = 0;
	}
	else if (c == 'E' || c == 'W')
	{
		if (c == 'W')
			sign = -1;
		player->dir[0] = 1 * sign;
		player->dir[1] = 0;
		player->dir_plane[0] = 0;
		player->dir_plane[1] = 0.66 * sign;
	}
}

static void	init_player(t_player *player, char **m)
{
	int	y;
	int	x;

	y = 0;
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == 'N' || m[y][x] == 'S' ||
				m[y][x] == 'W' || m[y][x] == 'E')
			{
				player->pos_x = x + 0.5;
				player->pos_y = y + 0.5;
				init_dir(player, m[y][x]);
			}
			x++;
		}
		y++;
	}
}

int	start_game(t_game game)
{
	t_frame		frame;
	t_player	player;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	game.win = mlx_new_window(game.mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	if (!game.win)
		return (0);
	init_player(&player, game.data.map);
	frame.img = mlx_new_image(game.mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!frame.img)
		return (0);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_length, &frame.endian);
	game.frame = &frame;
	game.player = &player;
	init_textures(&game);
	display_frame(game);
	mlx_key_hook(game.win, key_press, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (1);
}
