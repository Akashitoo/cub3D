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
	i = -1;
	step = (int)fmax(fabs(dx), fabs(dy));
	while (++i < step)
	{
		x += dx / step;
		y += dy / step;
		my_mlx_pixel_put(&frame, x, y, 0xFF0000);
	}
}

void	draw_stripe(t_frame frame, int x, int draw_start, int draw_end, int color)
{
	int	y;

	y = draw_start;
	while (y <= draw_end)
	{
		my_mlx_pixel_put(&frame, x, y, color);
		y++;
	}
}

void	draw_square(int x, int y, int sizex, int sizey, int color, t_frame frame)
{
	int	i;
	int	j;

	i = y;
	while (i < y + sizey)
	{
		j = x;
		while (j < x + sizex)
		{
			my_mlx_pixel_put(&frame, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_player player, t_frame frame)
{
	draw_square((player.pos_x) * 50, (player.pos_y) * 50, 5, 5, 0x7ac417, frame);
}

void	display_frame(t_game game)
{
	draw_square(0, 0, 800, 300, game.data.c_clr, *game.frame);
	draw_square(0, 300, 800, 300, game.data.f_clr, *game.frame);
	raycasting(game);
	mlx_put_image_to_window(game.mlx, game.win, game.frame->img, 0, 0);
}
