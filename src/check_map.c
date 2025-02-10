/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:54:41 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/22 10:37:14 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	isvalid_c(int c)
{
	if (c == '0' || c == '1' || ft_isspace(c))
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	ft_check_space(char **map, int y, int x)
{
	if (map[y + 1][x] && !ft_isspace(map[y + 1][x]) && map[y + 1][x] != '1')
		return (0);
	if (map[y - 1][x] && !ft_isspace(map[y - 1][x]) && map[y - 1][x] != '1')
		return (0);
	if (map[y][x + 1] && !ft_isspace(map[y][x + 1]) && map[y][x + 1] != '1')
		return (0);
	if (map[y][x - 1] && !ft_isspace(map[y][x - 1]) && map[y][x - 1] != '1')
		return (0);
	return (1);
}

static int	ft_check_start(char **map, int y, int x, int *cpt)
{
	*cpt += 1;
	if (!map[y + 1][x] || !map[y - 1][x] || !map[y][x + 1] || !map[y][x - 1])
		return (0);
	if (ft_isspace(map[y + 1][x]) || ft_isspace(map[y - 1][x]))
		return (0);
	if (ft_isspace(map[y][x + 1]) || ft_isspace(map[y][x - 1]))
		return (0);
	return (1);
}

static int	ft_check_zero(char **map, int y, int x)
{
	if (!map[y + 1][x] || !map[y - 1][x] || !map[y][x + 1] || !map[y][x - 1])
		return (0);
	if (ft_isspace(map[y + 1][x]) || ft_isspace(map[y - 1][x]))
		return (0);
	if (ft_isspace(map[y][x + 1]) || ft_isspace(map[y][x - 1]))
		return (0);
	return (1);
}

int	ft_check_map(char **map, int max)
{
	int	x;
	int	y;
	int	cpt;

	y = 0;
	cpt = 0;
	while (map[++y] && y < max)
	{
		x = 0;
		while (map[y][++x])
		{
			if (!isvalid_c(map[y][x]))
				return (0);
			if (map[y][x] == '0' && !ft_check_zero(map, y, x))
				return (0);
			else if (ft_isspace(map[y][x]) && !ft_check_space(map, y, x))
				return (0);
			else if (ft_isstart(map[y][x]) && !ft_check_start(map, y, x, &cpt))
				return (0);
		}
	}
	if (cpt != 1)
		return (0);
	return (1);
}
