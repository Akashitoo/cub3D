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

uint get_pixel_img(t_frame *data, int x, int y)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_stripe(t_game game, t_ray ray, int draw_start, int draw_end)
{
	int	y;
	int	color;
	double	step;
	double	text_y;

	step = 1.0 * TextHeight / ray.line_height;
	text_y = (draw_start - ScreenHeight / 2 + ray.line_height / 2) * step;
	y = draw_start;
	while (y <= draw_end)
	{
		color = get_pixel_img(game.textures[0], ray.text_x, (int)text_y);
		my_mlx_pixel_put(game.frame, ray.screen_x, y, color);
		text_y += step;
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
	int sw;
	int sh;

	sw = ScreenWidth;
	sh = ScreenHeight;
	draw_square(0, 0, sw, sh / 2, game.data.c_clr, *game.frame);
	draw_square(0, sh / 2, sw, sh / 2, game.data.f_clr, *game.frame);
	raycasting(game);
	mlx_put_image_to_window(game.mlx, game.win, game.frame->img, 0, 0);
}
