/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:08:59 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/22 10:23:55 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_maxlen(char **tab)
{
	int	i;
	int	len;
	int	max;

	if (!tab)
		return (0);
	max = 0;
	i = 6;
	while (tab[i])
	{
		len = ft_strlen(tab[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	ft_check_lim(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (map[y][++x])
	{
		if (map[y][x] != '1' && !ft_isspace(map[y][x]))
			return (-1);
	}
	x = 0;
	while (map[y])
	{
		if (map[y][x] != '1' && !ft_isspace(map[y][x]))
			return (-1);
		y++;
	}
	y--;
	while (map[y][x])
	{
		if (map[y][x] != '1' && !ft_isspace(map[y][x]))
			return (-1);
		x++;
	}
	return (y);
}

static int	ft_count_lines(char **tab, int pos)
{
	int	count;

	count = 0;
	if (!tab)
		return (0);
	while (tab[pos])
	{
		count++;
		pos++;
	}
	return (count);
}

char	**ft_create_map(char **tab, int max)
{
	char	**map;
	int		i;
	int		size;
	int		j;

	i = 6;
	size = ft_count_lines(tab, i);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	j = 0;
	while (tab[i])
	{
		map[j] = ft_strdup_max(tab[i], max);
		if (!map[j])
		{
			ft_clear_tab(&map, j);
			return (NULL);
		}
		i++;
		j++;
	}
	map[j] = 0;
	return (map);
}
