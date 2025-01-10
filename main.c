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

void	my_mlx_pixel_put(t_frame *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
			if (j == x || i == y)
				my_mlx_pixel_put(&frame, j, i, 0x000000);
			else
				my_mlx_pixel_put(&frame, j, i, color);
			j++;
		}
		i++;
	}
}
void draw_map(int map[10][10], int size, int color, t_frame frame)
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
			j++;
		}
		i++;
	}
}

int main(void)
{
	int	width;
	int height;
	void *mlx;
	void *mlx_win;
	t_frame frame;
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
	height = 500;
	width = 500;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Hello world!");
	frame.img = mlx_new_image(mlx, width, height);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length, &frame.endian);
	mlx_put_image_to_window(mlx, mlx_win, frame.img, 0, 0);
	draw_map(map, 10, 0xFFFFFF, frame);
	mlx_loop(mlx);
	(void)map;
	return(0);
}
