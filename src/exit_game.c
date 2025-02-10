/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:08:01 by mqwa              #+#    #+#             */
/*   Updated: 2025/02/09 03:43:34 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_minilibx(t_game *game, int index)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->frame->img)
		mlx_destroy_image(game->mlx, game->frame->img);
	if (game->textures[0] && index)
	{
		while (index-- > 0)
		{
			if (game->textures[index]->img)
				mlx_destroy_image(game->mlx, game->textures[index]->img);
			free(game->textures[index]);
		}
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	exit_game(t_game *game)
{
	ft_clear_all(game, "Thanks you for playing !\n", 0, 4);
	return (1);
}
