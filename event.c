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

int	check_collision(t_vars *vars, double pos_x, double pos_y)
{
	if (vars->map[(int)pos_y][(int)pos_x])
		return (1);
	return (0);
}

//int	key_press(int keycode, t_game *game)
//{
//	double	pos_x;
//	double	pos_y;
//	double	old_dir;
//	double	old_dir_plane;

//	pos_x = vars->player->pos_x;
//	pos_y = vars->player->pos_y;
//	if (keycode == 119 && !check_collision(vars, pos_x + (vars->player->dir[0] * 0.1), pos_y + (vars->player->dir[1] * 0.1)))
//	{
//		vars->player->pos_x += vars->player->dir[0] * 0.1;
//		vars->player->pos_y += vars->player->dir[1] * 0.1;
//	}
//	if (keycode == 115 && !check_collision(vars, pos_x - (vars->player->dir[0] * 0.1), pos_y - (vars->player->dir[1] * 0.1)))
//	{
//		// Le joueur se deplace de ~-5 pixels
//		vars->player->pos_x -= vars->player->dir[0] * 0.1;
//		vars->player->pos_y -= vars->player->dir[1] * 0.1;
//	}
//	if (keycode == 97)
//	{
//		vars->player->angle = -0.1;
//		old_dir = vars->player->dir[0];
//		old_dir_plane = vars->player->dir_plane[0];
//		// Modifie la direction du vecteur de -0.1 degré en appliquant une formule
//		vars->player->dir[0] = (vars->player->dir[0] * cosf(vars->player->angle)) - (vars->player->dir[1] * sinf(vars->player->angle));
//		vars->player->dir[1] = (old_dir * sinf(vars->player->angle) + (vars->player->dir[1] * cosf(vars->player->angle)));
//		vars->player->dir_plane[0] = (vars->player->dir_plane[0] * cosf(vars->player->angle)) - (vars->player->dir_plane[1] * sinf(vars->player->angle));
//		vars->player->dir_plane[1] = (old_dir_plane * sinf(vars->player->angle) + (vars->player->dir_plane[1] * cosf(vars->player->angle)));
//	}
//	if (keycode == 100)
//	{
//		vars->player->angle = 0.1;
//		old_dir = vars->player->dir[0];
//		old_dir_plane = vars->player->dir_plane[0];
//		// Modifie la direction du vecteur de -0.1 degré en appliquant une formule
//		vars->player->dir[0] = (vars->player->dir[0] * cosf(vars->player->angle)) - (vars->player->dir[1] * sinf(vars->player->angle));
//		vars->player->dir[1] = (old_dir * sinf(vars->player->angle) + (vars->player->dir[1] * cosf(vars->player->angle)));
//		vars->player->dir_plane[0] = (vars->player->dir_plane[0] * cosf(vars->player->angle)) - (vars->player->dir_plane[1] * sinf(vars->player->angle));
//		vars->player->dir_plane[1] = (old_dir_plane * sinf(vars->player->angle) + (vars->player->dir_plane[1] * cosf(vars->player->angle)));
//	}
//	display_frame(*vars->player, vars->map, *vars->frame, *vars);
//	return (0);
//}
