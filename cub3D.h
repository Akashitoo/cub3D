/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:06:38 by abalasub          #+#    #+#             */
/*   Updated: 2025/01/10 14:07:39 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>


typedef struct	s_ray {

	double	ray_X;
	double	ray_Y;
	double	delta_X;
	double	delta_Y;
	double	side_X;
	double	side_Y;
	int		step_X;
	int		step_Y;
	int		map_X;
	int		map_Y;
	int		side;
}				t_ray;

typedef struct	s_frame {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_frame;

typedef struct  s_player {
	
	double pos_x;
    double pos_y;
	double dir[2];
	double angle;
}               t_player;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_frame		*frame;
	t_player	*player;
	int			**map;
}				t_vars;

// Display 2D functions !

void	draw_line(t_frame frame, double x0, double y0, double x1, double y1);
void	draw_square(int x, int y, int size, int color, t_frame frame);
void	draw_player(t_player player, t_frame frame);
void	draw_map(int **map, int size, int color, t_frame frame);
void	displayFrame(t_player player, int **map, t_frame frame, t_vars vars);

void	my_mlx_pixel_put(t_frame *data, int x, int y, int color);

// Divers

void	calculateRay(t_frame frame, t_player player, int **map);

// Event

int	key_press(int keycode, t_vars *vars);

#endif
