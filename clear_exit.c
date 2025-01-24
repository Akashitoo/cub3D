/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:46:16 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/21 16:35:10 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_error(char *file, char *str)
{
	write(2, "Error\n", 6);
	if (file)
		write(2, file, ft_strlen(file));
	if (str)
		write(2, str, ft_strlen(str));
}

void	ft_clear_tab(char ***tab, int pos)
{
	int	i;

	i = 0;
	if (pos == -1)
	{
		while ((*tab)[i])
		{
			free((*tab)[i]);
			i++;
		}
	}
	else
	{
		while (i < pos)
		{
			free((*tab)[i]);
			i++;
		}
	}
	free((*tab));
}

void	ft_clear_parse(t_game *game, char *str)
{
	if (game->data.no_path)
		free(game->data.no_path);
	if (game->data.so_path)
		free(game->data.so_path);
	if (game->data.we_path)
		free(game->data.we_path);
	if (game->data.ea_path)
		free(game->data.ea_path);
	if (game->data.tab)
		ft_clear_tab(&game->data.tab, -1);
	if (game->data.map)
		ft_clear_tab(&game->data.map, -1);
	ft_exit_err(NULL, str, 1);
}

void	ft_clear_all(t_game *game, char *str)
{
	if (game->data.no_path)
		free(game->data.no_path);
	if (game->data.so_path)
		free(game->data.so_path);
	if (game->data.we_path)
		free(game->data.we_path);
	if (game->data.ea_path)
		free(game->data.ea_path);
	if (game->data.map)
		ft_clear_tab(&game->data.map, -1);
	ft_exit_err(NULL, str, 0);
}

void	ft_exit_err(char *file, char *str, int ex)
{
	if (str)
		ft_print_error(file, str);
	exit(ex);
}
