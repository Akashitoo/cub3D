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

#endif
