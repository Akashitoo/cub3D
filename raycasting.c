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

void    init_Ray(t_ray *ray, t_player player, double ray_X, double ray_Y)
{
	ray->ray_X = ray_X;
	ray->ray_Y = ray_Y;
	ray->map_X = (int)player.pos_x;
	ray->map_Y = (int)player.pos_y;
	ray->delta_X = sqrt(1 + (ray_Y * ray_Y) / (ray_X * ray_X));
	ray->delta_Y = sqrt(1 + (ray_X * ray_X) / (ray_Y * ray_Y));
	if (ray_X < 0)
	{
		ray->step_X = -1;
		ray->side_X = (player.pos_x - ray->map_X) * ray->delta_X;
	}
	else
	{
	    ray->step_X = 1;
	    ray->side_X = (ray->map_X + 1 - player.pos_x) * ray->delta_X;
	}
	if (ray_Y < 0)
	{
		ray->step_Y = -1;
		ray->side_Y = (player.pos_y - ray->map_Y) * ray->delta_Y;
	}
	else
	{
		ray->step_Y = 1;
		ray->side_Y = (ray->map_Y + 1 - player.pos_y) * ray->delta_Y;
	}
}

void draw_Ray(t_ray ray, t_player player, t_frame frame)
{
	double wall_Hit_pos;
	double pos_x;
	double pos_y;
	int     map_X;
	int     map_Y;
	
	pos_x = player.pos_x;
	pos_y = player.pos_y;
	map_X = ray.map_X;
	map_Y = ray.map_Y;
	if (ray.side == 0)
	{
		if (ray.step_X < 0)
			map_X -= ray.step_X;
		wall_Hit_pos = (ray.ray_Y / ray.ray_X) * (fabs(map_X - pos_x) * ray.step_X);
		draw_line(frame, pos_x * 50, pos_y * 50, map_X * 50, (pos_y + wall_Hit_pos) * 50);
	}
	else
	{
		if (ray.step_Y < 0)
			map_Y -= ray.step_Y;
		wall_Hit_pos = (ray.ray_X / ray.ray_Y) * (fabs(map_Y - pos_y) * ray.step_Y);
		draw_line(frame, pos_x * 50, pos_y * 50, (pos_x + wall_Hit_pos) * 50, map_Y * 50);
	}
}

void calculateRay(t_frame frame, t_player player, int **map)
{
	t_ray   ray;
	int     hit;
	
	init_Ray(&ray, player, player.dir[0], player.dir[1]);
	hit = 0;
	while (hit == 0)
	{
		if (ray.side_X < ray.side_Y)
		{
			ray.side_X += ray.delta_X;
			ray.map_X += ray.step_X;
			ray.side = 0;
		}
		else
		{
			ray.side_Y += ray.delta_Y;
			ray.map_Y += ray.step_Y;
			ray.side = 1;
		}
		if (map[ray.map_Y][ray.map_X])
			hit = 1;
	}
	draw_Ray(ray, player, frame);
}
