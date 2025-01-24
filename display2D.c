/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:27:48 by abalasub          #+#    #+#             */
/*   Updated: 2025/01/21 16:27:50 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_frame frame, double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		step;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	i = 0;
	step = (int)fmax(fabs(dx), fabs(dy));
	while (i < step)
	{
		x += dx / step;
		y += dy / step;
		my_mlx_pixel_put(&frame, x, y, 0xFF0000);
		i++;
	}
}

void	draw_stripe(t_frame frame, int x, int draw_start, int draw_end
	, int color)
{
	int	y;

	y = draw_start;
	while (y <= draw_end)
	{
		my_mlx_pixel_put(&frame, x, y, color);
		y++;
	}
}

void	draw_square(int x, int y, int size, int color, t_frame frame)
{
	int	i;
	int	j;

	i = y;
	while (i < y + size)
	{
		j = x;
		while (j < x + size)
		{
			if (i == y || i == y + size - 1 || j == x || j == x + size - 1)
				my_mlx_pixel_put(&frame, j, i, color);
			else
				my_mlx_pixel_put(&frame, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_player player, t_frame frame)
{
	draw_square((player.pos_x) * 50, (player.pos_y) * 50, 5, 0x7ac417, frame);
}

void	draw_map(int **map, int size, int color, t_frame frame)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == 1)
				draw_square(j * 50, i * 50, 50, color, frame);
			else if (map[i][j] == 0)
				draw_square(j * 50, i * 50, 50, 0x000000, frame);
			j++;
		}
		i++;
	}
}

void	display_frame(t_player player, int **map, t_frame frame, t_vars vars)
{
	//draw_map(map, 10, 0xFFFFFF, frame);
	//draw_player(player, frame);
	//calculateRay(frame, player, map);
	draw_square(0, 0, 250, 0x0022AA, frame);
	draw_square(250, 0, 250, 0x0022AA, frame);
	draw_square(0, 250, 250, 0x0022AA / 2, frame);
	draw_square(250, 250, 250, 0x0022AA / 2, frame);
	raycasting(frame, player, map);
	mlx_put_image_to_window(vars.mlx, vars.win, frame.img, 0, 0);
}
