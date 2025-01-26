/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:16:51 by abalasub          #+#    #+#             */
/*   Updated: 2025/01/21 17:17:07 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_collision(t_game *game, double pos_x, double pos_y)
{
	if (game->data.map[(int)pos_y][(int)pos_x] == '1')
		return (1);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	double	pos_x;
	double	pos_y;
	double	old_dir;
	double	old_dir_plane;

	pos_x = game->player->pos_x;
	pos_y = game->player->pos_y;
	if (keycode == 119 && !check_collision(game, pos_x + (game->player->dir[0] * 0.1), pos_y + (game->player->dir[1] * 0.1)))
	{
		game->player->pos_x += game->player->dir[0] * 0.1;
		game->player->pos_y += game->player->dir[1] * 0.1;
	}
	if (keycode == 115 && !check_collision(game, pos_x - (game->player->dir[0] * 0.1), pos_y - (game->player->dir[1] * 0.1)))
	{
		// Le joueur se deplace de ~-5 pixels
		game->player->pos_x -= game->player->dir[0] * 0.1;
		game->player->pos_y -= game->player->dir[1] * 0.1;
	}
	if (keycode == 97)
	{
		game->player->angle = -0.1;
		old_dir = game->player->dir[0];
		old_dir_plane = game->player->dir_plane[0];
		// Modifie la direction du vecteur de -0.1 degré en appliquant une formule
		game->player->dir[0] = (game->player->dir[0] * cosf(game->player->angle)) - (game->player->dir[1] * sinf(game->player->angle));
		game->player->dir[1] = (old_dir * sinf(game->player->angle) + (game->player->dir[1] * cosf(game->player->angle)));
		game->player->dir_plane[0] = (game->player->dir_plane[0] * cosf(game->player->angle)) - (game->player->dir_plane[1] * sinf(game->player->angle));
		game->player->dir_plane[1] = (old_dir_plane * sinf(game->player->angle) + (game->player->dir_plane[1] * cosf(game->player->angle)));
	}
	if (keycode == 100)
	{
		game->player->angle = 0.1;
		old_dir = game->player->dir[0];
		old_dir_plane = game->player->dir_plane[0];
		// Modifie la direction du vecteur de -0.1 degré en appliquant une formule
		game->player->dir[0] = (game->player->dir[0] * cosf(game->player->angle)) - (game->player->dir[1] * sinf(game->player->angle));
		game->player->dir[1] = (old_dir * sinf(game->player->angle) + (game->player->dir[1] * cosf(game->player->angle)));
		game->player->dir_plane[0] = (game->player->dir_plane[0] * cosf(game->player->angle)) - (game->player->dir_plane[1] * sinf(game->player->angle));
		game->player->dir_plane[1] = (old_dir_plane * sinf(game->player->angle) + (game->player->dir_plane[1] * cosf(game->player->angle)));
	}
	display_frame(*game->player, game->data.map, *game->frame, *game);
	return (0);
}
