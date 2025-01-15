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

void	draw_line(t_frame frame, int x0, int y0, int x1, int y1)
{
	float slope;
	int x;
	float y;
	if (x0 > x1)
		draw_line(frame, x1 ,y1, x0 , y0);
	slope = (float)(y1 - y0) / (float)(x1 - x0);
	x = x0;
	while (x <= x1)
	{
		y = slope * (x - x0) + y0;
		//printf("%d %d\n",x ,y);
		my_mlx_pixel_put(&frame, x, y, 0xFF0000);
		(void) frame;
		x++;
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
			my_mlx_pixel_put(&frame, j, i, color);
			j++;
		}
		i++;
	}
}

void draw_player(t_player player, t_frame frame)
{
	draw_square(player.pos_x , player.pos_y , 5,0x7ac417, frame);
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
	draw_line(frame, (int)player.pos_x, (int)player.pos_y, (int)player.pos_x + ((int)player.dir[0] * 100), (int)player.pos_y + ((int)player.dir[1] * 100));
	//draw_line(frame, (int)player.pos_x, (int)player.pos_y, (int)player.pos_x + 100, 0);
	printf("dirX : %f dirY : %f\n", vars.player->dir[0], vars.player->dir[1]);
	mlx_put_image_to_window(vars.mlx, vars.win, frame.img, 0, 0);
}

int checkCollision(t_vars *vars, float pos_x, float pos_y)
{
	if (vars->map[(int)pos_y/50][(int)pos_x/50])
		return (1);
	return (0);
}

int key_press(int keycode, t_vars *vars)
{
	int	pos_x;
	int pos_y;
	float oldDir;

	pos_x = vars->player->pos_x;
	pos_y = vars->player->pos_y;
	if (keycode == 119 && !checkCollision(vars, pos_x, pos_y))
	{
		vars->player->pos_x += vars->player->dir[0] * 5;
		vars->player->pos_y +=vars->player->dir[1] * 5;
	}
	if (keycode == 115 && !checkCollision(vars, pos_x, pos_y))
	{
		vars->player->pos_x = pos_x - (vars->player->dir[0] * 3);
		vars->player->pos_y = pos_y - (vars->player->dir[1] * 3);
	}
	if (keycode == 97)
	{
		//vars->player->pos_x -= speed;
		vars->player->angle = -0.1;
		oldDir = vars->player->dir[0];
		vars->player->dir[0] = (vars->player->dir[0] * cosf(vars->player->angle)) - (vars->player->dir[1] * sinf(vars->player->angle));
		vars->player->dir[1] = (oldDir * sinf(vars->player->angle) + (vars->player->dir[1] * cosf(vars->player->angle)));
	}
	if (keycode == 100)
	{
		//vars->player->pos_x += speed;
		vars->player->angle = 0.1;
		oldDir = vars->player->dir[0];
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
	int map[10][10] = {{1,1,1,1,1,1,1,1,1,1},
					   {1,0,0,0,0,0,0,0,0,1},
				       {1,0,0,0,0,0,0,0,0,1},
				       {1,0,0,0,0,0,0,0,0,1},
				       {1,0,0,0,1,1,0,0,0,1},
				       {1,0,0,0,0,0,0,0,0,1},
				       {1,0,0,0,0,0,1,0,0,1},
				       {1,0,0,0,0,0,0,0,0,1},
				       {1,0,1,0,0,0,0,0,0,1},
				       {1,1,1,1,1,1,1,1,1,1}};

	player.pos_x = 380;
	player.pos_y = 380;
	player.dir[0] = 1;
	player.dir[1] = 1;
	player.angle = 45;

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
