/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:16:51 by abalasub          #+#    #+#             */
/*   Updated: 2025/02/09 03:43:46 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_collision(t_game *game, double stepx, double stepy)
{
	double	pos_x;
	double	pos_y;

	pos_x = game->player->pos_x;
	pos_y = game ->player->pos_y;
	if (game->data.map[(int)pos_y][(int)(pos_x + stepx)] == '1'
			|| game->data.map[(int)(pos_y + stepy)][(int)pos_x] == '1')
		return (1);
	else if (game->data.map[(int)(pos_y + stepy)][(int)(pos_x + stepx)] == '1')
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
	double	stepx;
	double	stepy;

	stepx = game->player->dir[0] * step;
	stepy = game->player->dir[1] * step;
	if (!check_collision(game, stepx, stepy))
	{
		game->player->pos_x += stepx;
		game->player->pos_y += stepy;
	}
}

void	move_ad(t_game *game, double step)
{
	double	stepx;
	double	stepy;

	stepx = (game->player->dir_plane[0] * step);
	stepy = (game->player->dir_plane[1] * step);
	if (!check_collision(game, stepx, stepy))
	{
		game->player->pos_x += stepx;
		game->player->pos_y += stepy;
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->w = 1;
	if (keycode == XK_s)
		game->s = 1;
	if (keycode == XK_a)
		game->a = 1;
	if (keycode == XK_d)
		game->d = 1;
	if (keycode == XK_Left)
		game->l = 1;
	if (keycode == XK_Right)
		game->r = 1;
	if (keycode == ESC)
		ft_clear_all(game, "Thanks you for playing !\n", 0, 4);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->w = 0;
	if (keycode == XK_s)
		game->s = 0;
	if (keycode == XK_a)
		game->a = 0;
	if (keycode == XK_d)
		game->d = 0;
	if (keycode == XK_Left)
		game->l = 0;
	if (keycode == XK_Right)
		game->r = 0;
	return (0);
}

int	move(t_game *game)
{
	if (game->w == 1)
		move_ws(game, 0.01);
	if (game->s == 1)
		move_ws(game, -0.01);
	if (game->a == 1)
		move_ad(game, -0.01);
	if (game->d == 1)
		move_ad(game, 0.01);
	if (game->l == 1)
		turn_camera(game, -0.005);
	if (game->r == 1)
		turn_camera(game, 0.005);
	display_frame(*game);
	return (0);
}


// if (keycode == XK_w)
// move_ws(game, 0.2);
// if (keycode == XK_s)
// move_ws(game, -0.2);
// if (keycode == XK_a)
// move_ad(game, -0.2);
// if (keycode == XK_d)
// move_ad(game, 0.2);
// if (keycode == XK_Left)
// turn_camera(game, -0.2);
// if (keycode == XK_Right)
// turn_camera(game, 0.2);
// if (keycode == ESC)
// ft_clear_all(game, "Thanks you for playing !\n", 0, 4);
// display_frame(*game);
// return (0);
