/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:25:27 by abalasub          #+#    #+#             */
/*   Updated: 2025/01/21 20:18:12 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray(t_ray *ray, t_player player, double ray_x, double ray_y)
{
	ray->ray_x = ray_x;
	ray->ray_y = ray_y;
	ray->map_x = (int)player.pos_x;
	ray->map_y = (int)player.pos_y;
	ray->delta_x = fabs(1 / ray_x);
	ray->delta_y = fabs(1 / ray_y);
	if (ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player.pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1 - player.pos_x) * ray->delta_x;
	}
	if (ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player.pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1 - player.pos_y) * ray->delta_y;
	}
}

t_ray	calculate_ray(t_player player, char **map, double ray_x, double ray_y)
{
	t_ray	ray;
	int		hit;

	init_ray(&ray, player, ray_x, ray_y);
	hit = 0;
	while (hit == 0)
	{
		if (ray.side_x < ray.side_y)
		{
			ray.side_x += ray.delta_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_y += ray.delta_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (map[ray.map_y][ray.map_x] == '1')
			hit = 1;
	}
	return (ray);
}

void	texture_x(t_ray *ray, t_game game)
{
	double	wall_hit_x;
	double	pos_x;
	double	pos_y;

	pos_x = game.player->pos_x;
	pos_y = game.player->pos_y;
	if (ray->side == 0)
		wall_hit_x = pos_y + ((ray->side_x - ray->delta_x) * ray->ray_y);
	else
		wall_hit_x = pos_x + ((ray->side_y - ray->delta_y) * ray->ray_x);
	wall_hit_x -= (int)wall_hit_x;
	ray->text_x = (int)(wall_hit_x * (double)TextWidth);
	ray->text_x = TextWidth - ray->text_x - 1;
}

void	display_stripe(t_ray ray, t_game game)
{
	int		d_start;
	int		d_end;

	if (ray.side == 0)
		ray.line_height = (int)(ScreenHeight / (ray.side_x - ray.delta_x));
	else
		ray.line_height = (int)(ScreenHeight / (ray.side_y - ray.delta_y));
	d_start = (-ray.line_height / 2) + (ScreenHeight / 2);
	if (d_start < 0)
		d_start = 0;
	d_end = (ray.line_height / 2) + (ScreenHeight / 2);
	if (d_end >= ScreenHeight)
		d_end = ScreenHeight - 1;
	texture_x(&ray, game);
	draw_stripe(game, ray, d_start, d_end);
}

void	raycasting(t_game game)
{
	int		x;
	double	ray_x;
	double	ray_y;
	double	camerax;
	t_ray	ray;

	x = 0;
	while (x < ScreenWidth)
	{
		camerax = ((2 * x) / (double)ScreenWidth) - 1;
		ray_x = game.player->dir[0] + game.player->dir_plane[0] * camerax;
		ray_y = game.player->dir[1] + game.player->dir_plane[1] * camerax;
		ray = calculate_ray(*game.player, game.data.map, ray_x, ray_y);
		ray.screen_x = x;
		display_stripe(ray, game);
		x += 1;
	}
}
