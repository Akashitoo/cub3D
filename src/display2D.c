/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:27:48 by abalasub          #+#    #+#             */
/*   Updated: 2025/02/09 03:08:33 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_wall(t_ray ray)
{
	if (ray.side == 0)
	{
		if (ray.ray_x > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (ray.ray_y < 0)
			return (0);
		else
			return (1);
	}
}

void	draw_stripe(t_game game, t_ray ray, int draw_start, int draw_end)
{
	int		y;
	int		wall_text;
	int		color;
	double	step;
	double	text_y;

	wall_text = get_wall(ray);
	step = 1.0 * TEXTHEIGHT / ray.line_height;
	text_y = (draw_start - SCREENHEIGHT / 2 + ray.line_height / 2) * step;
	y = draw_start;
	while (y <= draw_end)
	{
		color = get_pixel_img(game.textures[wall_text],
				ray.text_x, (int)text_y);
		my_mlx_pixel_put(game.frame, ray.screen_x, y, color);
		text_y += step;
		y++;
	}
}

void	draw_ceiling(t_frame frame, int color)
{
	int	size_height;
	int	x;
	int	y;

	size_height = SCREENHEIGHT / 2;
	y = 0;
	while (y < size_height)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			my_mlx_pixel_put(&frame, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_frame frame, int color)
{
	int	size_height;
	int	x;
	int	y;

	size_height = SCREENHEIGHT;
	y = SCREENHEIGHT / 2;
	while (y < size_height)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			my_mlx_pixel_put(&frame, x, y, color);
			x++;
		}
		y++;
	}
}

void	display_frame(t_game game)
{
	draw_ceiling(*game.frame, game.data.c_clr);
	draw_floor(*game.frame, game.data.f_clr);
	raycasting(game);
	mlx_put_image_to_window(game.mlx, game.win, game.frame->img, 0, 0);
}
