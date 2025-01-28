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

int	main(int ac, char **av)
{
	if (ac == 2)
		setup_game(av[1]);
	ft_print_error(NULL, "cub3D take one argument\n");
	return (1);
}
