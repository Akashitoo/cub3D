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
	*(unsigned int*)dst = color;
}

void draw_line(t_frame frame, double x0, double y0, double x1, double y1)
{
	double dx;
	double dy;
	int step;
	int i;
	double x;
	double y;

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

void draw_line2(int **map, t_frame frame, double x0, double y0, double x1, double y1)
{
	double dx;
	double dy;
	int step;
	int i;
	double x;
	double y;

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
		if (map[(int)y/50][(int)x/50])
			return;
		my_mlx_pixel_put(&frame, x, y, 0x00AABB);
		i++;
	}
}

 void	calculateRay(t_frame frame, t_player player, int **map)
 {
	int mapX;
	int mapY;

 	double deltaDistX;
	double deltaDistY;

	double sideDistX;
	double sideDistY;

	int side;
	int hit;

	int stepX;
	int stepY;

	mapX = (int)player.pos_x;
	mapY = (int)player.pos_y;

	deltaDistX = sqrt(1 + (player.dir[1] * player.dir[1]) / (player.dir[0] * player.dir[0]));
	deltaDistY = sqrt(1 + (player.dir[0] * player.dir[0]) / (player.dir[1] * player.dir[1]));
	
	hit = 0;	
	
	if (player.dir[0] < 0)
	{
		stepX = -1;
		sideDistX = (player.pos_x - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1 - player.pos_x) * deltaDistX;
	}
	if (player.dir[1] < 0)
	{
		stepY = -1;
		sideDistY = (player.pos_y - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1 - player.pos_y) * deltaDistY;
	}
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		if (map[mapY][mapX])
			hit = 1;
	}

	if (side == 0)
	{
		if(stepX < 0)
			mapX -= stepX;
		printf("rayX : %d, rayY : %lf \n", mapX, player.pos_y + (player.dir[0] / player.dir[1] * (fabs(mapX - player.pos_x))));
		draw_line(frame, player.pos_x * 50, player.pos_y * 50, mapX * 50, (player.pos_y + ((player.dir[1] / player.dir[0]) * ((fabs(mapX - player.pos_x) * stepX)))) * 50);
	}
	else
	{
		if (stepY < 0)
			mapY -= stepY;
		printf("rayX : %lf, rayY : %d \n", (player.pos_x + (sideDistY / deltaDistY) * player.dir[0]), mapY);
		draw_line(frame, player.pos_x * 50, player.pos_y * 50, (player.pos_x + ((player.dir[0] / player.dir[1]) * (fabs(mapY - player.pos_y) * stepY)))* 50, mapY * 50);
	}
 }

void	initMap(t_vars *vars, int map[10][10])
{
	int i;
	int j;

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

void	draw_square(int x, int y, int size, int color, t_frame frame)
{
	int i;
	int j;

	i = y;
	while (i < y + size)
	{
		j = x;
		while (j < x + size)
		{
			if (i == y || i == y+size-1 || j == x || j == x+size-1)
				my_mlx_pixel_put(&frame,j, i, 0xAA0000);
			else
				my_mlx_pixel_put(&frame, j, i, color);
			j++;
		}
		i++;
	}
}

void draw_player(t_player player, t_frame frame)
{
	draw_square((player.pos_x) * 50, (player.pos_y) * 50, 5,0x7ac417, frame);
}

void draw_map(int **map, int size, int color, t_frame frame)
{
	int i;
	int j;

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

void displayFrame(t_player player, int **map, t_frame frame, t_vars vars)
{
	
	draw_map(map, 10, 0xFFFFFF, frame);
	draw_player(player, frame);
	calculateRay(frame, player, map);
	// Desssine un rayon de ~100 pixels depuis le joueur 
	//draw_line2(map, frame, player.pos_x * 50, player.pos_y * 50, (player.pos_x * 50) + player.dir[0] * 300, (player.pos_y * 50) + player.dir[1] * 300);
	//printf("dirX : %f dirY : %f\n", vars.player->dir[0], vars.player->dir[1]);
	mlx_put_image_to_window(vars.mlx, vars.win, frame.img, 0, 0);
}

int checkCollision(t_vars *vars, double pos_x, double pos_y)
{
	if (vars->map[(int)pos_y][(int)pos_x])
		return (1);
	return (0);
}

int key_press(int keycode, t_vars *vars)
{
	double	pos_x;
	double 	pos_y;
	double 	oldDir;

	pos_x = vars->player->pos_x;
	pos_y = vars->player->pos_y;
	if (keycode == 119 && !checkCollision(vars, pos_x + (vars->player->dir[0] * 0.1) , pos_y + (vars->player->dir[1] * 0.1)))
	{
		vars->player->pos_x += vars->player->dir[0] * 0.1;
		vars->player->pos_y += vars->player->dir[1] * 0.1;
	}
	if (keycode == 115 && !checkCollision(vars, pos_x - (vars->player->dir[0] * 0.1), pos_y - (vars->player->dir[1] * 0.1)))
	{
		// Le joueur se deplace de ~-5 pixels
		vars->player->pos_x -= vars->player->dir[0] * 0.1;
		vars->player->pos_y -= vars->player->dir[1] * 0.1;
	}
	if (keycode == 97)
	{
		vars->player->angle = -0.1;
		oldDir = vars->player->dir[0];
		// Modifie la direction du vecteur de -0.1 degré en appliquant une formule
		vars->player->dir[0] = (vars->player->dir[0] * cosf(vars->player->angle)) - (vars->player->dir[1] * sinf(vars->player->angle));
		vars->player->dir[1] = (oldDir * sinf(vars->player->angle) + (vars->player->dir[1] * cosf(vars->player->angle)));
	}
	if (keycode == 100)
	{
		vars->player->angle = 0.1;
		oldDir = vars->player->dir[0];
		// Modifie la direction du vecteur de -0.1 degré en appliquant une formule
		vars->player->dir[0] = (vars->player->dir[0] * cosf(vars->player->angle)) - (vars->player->dir[1] * sinf(vars->player->angle));
		vars->player->dir[1] = (oldDir * sinf(vars->player->angle) + (vars->player->dir[1] * cosf(vars->player->angle)));
	}
	displayFrame(*vars->player, vars->map, *vars->frame, *vars);
	return (0);
}

int main(void)
{
	int	width;
	int height;
	t_frame frame;
	t_player player;
	t_vars vars;
	int map[10][10] =
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};

	player.pos_x = 3;
	player.pos_y = 3;
	player.dir[0] = -1;
	player.dir[1] = 0;

	height = 500;
	width = 500;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "cub3d");
	frame.img = mlx_new_image(vars.mlx, width, height);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length, &frame.endian);
	vars.player = &player;
	vars.frame = &frame;
	initMap(&vars, map);
	displayFrame(player, vars.map, frame, vars);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);
	return(0);
}
