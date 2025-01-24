/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:46:53 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/21 16:35:04 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**ft_voidless_tab(char **tab, int size)
{
	char	**new_tab;
	int		i;
	int		j;

	new_tab = malloc(sizeof(char *) * (size + 1));
	if (!new_tab)
		return (NULL);
	i = 0;
	j = -1;
	while (tab[++j] && i < size)
	{
		if (!ft_check_empty(tab[j]))
		{
			new_tab[i] = ft_strdup(tab[j]);
			if (!new_tab[i++])
			{
				ft_clear_tab(&new_tab, i - 1);
				ft_clear_tab(&tab, -1);
				return (NULL);
			}
		}
	}
	new_tab[i] = NULL;
	ft_clear_tab(&tab, -1);
	return (new_tab);
}

int	ft_create_tab(t_game *game)
{
	int	count;
	int	i;

	game->data.tab = ft_split(game->data.line, '\n');
	free(game->data.line);
	if (!game->data.tab)
		return (0);
	count = 0;
	i = -1;
	while (game->data.tab[++i])
	{
		if (!ft_check_empty(game->data.tab[i]))
			count++;
	}
	if (count < 9)
	{
		ft_clear_tab(&game->data.tab, -1);
		ft_exit_err(NULL, "Wrong file format\n", 1);
	}
	if (count == i)
		return (1);
	game->data.tab = ft_voidless_tab(game->data.tab, count);
	if (!game->data.tab)
		return (0);
	return (1);
}
