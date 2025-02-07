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

void	turn_camera(t_game *game, double angle)
{
	double	old_dir;
	double	old_dir_plane;

	old_dir = game->player->dir[0];
	old_dir_plane = game->player->dir_plane[0];
	game->player->dir[0] = (game->player->dir[0] * cosf(angle))
		- (game->player->dir[1] * sinf(angle));
	game->player->dir[1] = (old_dir * sinf(angle)
			+ (game->player->dir[1] * cosf(angle)));
	game->player->dir_plane[0] = (game->player->dir_plane[0] * cosf(angle))
		- (game->player->dir_plane[1] * sinf(angle));
	game->player->dir_plane[1] = (old_dir_plane * sinf(angle)
			+ (game->player->dir_plane[1] * cosf(angle)));
}

void	move_ws(t_game *game, double step)
{
	double	next_pos_x;
	double	next_pos_y;

	next_pos_x = game->player->pos_x + (game->player->dir[0] * step);
	next_pos_y = game->player->pos_y + (game->player->dir[1] * step);
	if (!check_collision(game, next_pos_x, next_pos_y))
	{
		game->player->pos_x = next_pos_x;
		game->player->pos_y = next_pos_y;
	}
}

void	move_ad(t_game *game, double step)
{
	double	next_pos_x;
	double	next_pos_y;

	next_pos_x = game->player->pos_x + (game->player->dir_plane[0] * step);
	next_pos_y = game->player->pos_y + (game->player->dir_plane[1] * step);
	if (!check_collision(game, next_pos_x, next_pos_y))
	{
		game->player->pos_x = next_pos_x;
		game->player->pos_y = next_pos_y;
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 119)
		move_ws(game, 0.1);
	if (keycode == 115)
		move_ws(game, -0.1);
	if (keycode == 97)
		move_ad(game, -0.1);
	if (keycode == 100)
		move_ad(game, 0.1);
	if (keycode == 65361)
		turn_camera(game, -0.2);
	if (keycode == 65363)
		turn_camera(game, 0.2);
	display_frame(*game);
	return (0);
}
