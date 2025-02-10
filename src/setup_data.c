/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:43:28 by mqwa              #+#    #+#             */
/*   Updated: 2025/02/08 22:54:14 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_get_path(t_game *game, char *buf, char *str)
{
	if (!ft_strcmp(buf, "NO") && !game->data.no_nb)
		game->data.no_p = ft_fill_path(game, str, &game->data.no_nb);
	else if (!ft_strcmp(buf, "SO") && !game->data.so_nb)
		game->data.so_p = ft_fill_path(game, str, &game->data.so_nb);
	else if (!ft_strcmp(buf, "WE") && !game->data.we_nb)
		game->data.we_p = ft_fill_path(game, str, &game->data.we_nb);
	else if (!ft_strcmp(buf, "EA") && !game->data.ea_nb)
		game->data.ea_p = ft_fill_path(game, str, &game->data.ea_nb);
	else if (!ft_strcmp(buf, "F") && !game->data.f_nb)
		game->data.f_clr = ft_fill_color(str, &game->data.f_nb);
	else if (!ft_strcmp(buf, "C") && !game->data.c_nb)
		game->data.c_clr = ft_fill_color(str, &game->data.c_nb);
	else
		return (0);
	if (game->data.f_clr == -1 || game->data.c_clr == -1)
		ft_clear_parse(game, "Wrong color format\n");
	return (1);
}

static int	ft_count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
			count++;
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	return (count);
}

static int	ft_fill_data(t_game *game, char *str)
{
	char	buf[3];
	int		i;
	int		j;

	if (ft_count_word(str) != 2)
		return (0);
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	j = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		buf[j++] = str[i++];
		if (j > 2)
			return (0);
	}
	buf[j] = '\0';
	if (!ft_get_path(game, buf, str))
		return (0);
	return (1);
}

int	ft_setup_data(t_game *game)
{
	int	i;
	int	max;

	i = 0;
	while (i < 6)
	{
		if (!ft_fill_data(game, game->data.tab[i]))
			return (0);
		i++;
	}
	max = ft_get_maxlen(game->data.tab);
	if (!max)
		return (0);
	game->data.map = ft_create_map(game->data.tab, max);
	if (!game->data.map)
		ft_clear_parse(game, "Map malloc error\n");
	max = ft_check_lim(game->data.map);
	if (max == -1)
		ft_clear_parse(game, "Invalid map\n");
	if (!ft_check_map(game->data.map, max))
		ft_clear_parse(game, "Invalid map\n");
	ft_clear_tab(&game->data.tab, -1);
	return (1);
}
