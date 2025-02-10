/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:46:16 by mqwa              #+#    #+#             */
/*   Updated: 2025/02/09 02:02:56 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_error(char *file, char *str, int ex)
{
	int	res;

	if (ex)
		res = write(2, "Error\n", 6);
	if (file)
		res = write(2, file, ft_strlen(file));
	if (str)
		res = write(2, str, ft_strlen(str));
	(void)res;
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
	if (game->data.no_p)
		free(game->data.no_p);
	if (game->data.so_p)
		free(game->data.so_p);
	if (game->data.we_p)
		free(game->data.we_p);
	if (game->data.ea_p)
		free(game->data.ea_p);
	if (game->data.tab)
		ft_clear_tab(&game->data.tab, -1);
	if (game->data.map)
		ft_clear_tab(&game->data.map, -1);
	ft_exit_err(NULL, str, 1);
}

void	ft_clear_all(t_game *game, char *str, int ex, int index)
{
	if (game->data.no_p)
		free(game->data.no_p);
	if (game->data.so_p)
		free(game->data.so_p);
	if (game->data.we_p)
		free(game->data.we_p);
	if (game->data.ea_p)
		free(game->data.ea_p);
	if (game->data.map)
		ft_clear_tab(&game->data.map, -1);
	if (game->mlx)
		clear_minilibx(game, index);
	ft_exit_err(NULL, str, ex);
}

void	ft_exit_err(char *file, char *str, int ex)
{
	if (str)
		ft_print_error(file, str, ex);
	exit(ex);
}
