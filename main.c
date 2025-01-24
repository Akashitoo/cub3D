/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:49:46 by abalasub          #+#    #+#             */
/*   Updated: 2025/01/10 13:51:14 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_frame *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_map(t_vars *vars, int map[10][10])
{
	int	i;
	int	j;

	i = 0;
	vars->map = malloc(sizeof(int *) * 10);
	while (i < 10)
	{
		j = 0;
		vars->map[i] = malloc(sizeof(int) * 10);
		while (j < 10)
		{
			vars->map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

//int	old_main(void)
//{
//	int			width;
//	int			height;
//	t_frame		frame;
//	t_player	player;
//	t_vars		vars;
//	int			map[10][10] =
//	{
//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//	{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//	{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//	};

//	player.pos_x = 3;
//	player.pos_y = 3;
//	player.dir[0] = -1;
//	player.dir[1] = 0;
//	player.dir_plane[0] = 0;
//	player.dir_plane[1] = -0.50;
//	height = 500;
//	width = 500;
//	vars.mlx = mlx_init();
//	vars.win = mlx_new_window(vars.mlx, width, height, "cub3d");
//	frame.img = mlx_new_image(vars.mlx, width, height);
//	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length, &frame.endian);
//	vars.player = &player;
//	vars.frame = &frame;
//	init_map(&vars, map);
//	display_frame(player, vars.map, frame, vars);
//	mlx_key_hook(vars.win, key_press, &vars);
//	mlx_loop(vars.mlx);
//	return(0);
//}

int	main(int ac, char **av)
{
	if (ac == 2)
		setup_game(av[1]);
	ft_print_error(NULL, "cub3D take one argument\n");
	return (1);
}
