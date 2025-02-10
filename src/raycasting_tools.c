/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 03:03:25 by mqwa              #+#    #+#             */
/*   Updated: 2025/02/09 03:03:31 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_ray_tools(t_ray *ray, t_player player, double ray_x, double ray_y)
{
	ray->ray_x = ray_x;
	ray->ray_y = ray_y;
	ray->map_x = (int)player.pos_x;
	ray->map_y = (int)player.pos_y;
	ray->delta_x = fabs(1 / ray_x);
	ray->delta_y = fabs(1 / ray_y);
}
