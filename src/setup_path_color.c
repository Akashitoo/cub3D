/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_path_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:50:55 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/21 15:06:46 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_get_clr_value(char *str, int *pos)
{
	char	buf[4];
	int		i;

	i = 0;
	while (str[*pos] && str[*pos] != ',')
	{
		buf[i] = str[*pos];
		i++;
		*pos += 1;
	}
	buf[i] = '\0';
	if (str[*pos] && str[*pos] == ',')
		*pos += 1;
	return (ft_atoi(buf));
}

int	ft_fill_color(char *str, int *nb)
{
	int	i;
	int	r;
	int	g;
	int	b;

	*nb += 1;
	if (!check_color_str(str))
		return (-1);
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	r = ft_get_clr_value(str, &i);
	g = ft_get_clr_value(str, &i);
	b = ft_get_clr_value(str, &i);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (-1);
	return ((b << 0) + (g << 8) + (r << 16));
}

char	*ft_fill_path(t_game *game, char *str, int *nb)
{
	char	*path;
	int		i;
	int		size;

	*nb += 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	size = 0;
	while (str[i + size] && !ft_isspace(str[i + size]))
		size++;
	path = malloc(sizeof(char) * (size + 1));
	if (!path)
		ft_clear_parse(game, "Malloc error\n");
	size = 0;
	while (str[i] && !ft_isspace(str[i]))
		path[size++] = str[i++];
	path[size] = '\0';
	return (path);
}
