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
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 2048
# define ScreenWidth 800
# define ScreenHeight 600

typedef struct	s_ray {

	double	ray_x;
	double	ray_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
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
	double dir_plane[2];
	double angle;
}               t_player;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_frame		*frame;
	t_player	*player;
	int			**map;
}				t_vars;

typedef struct s_data
{
	char	**tab;
	char	**map;
	char	*line;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		f_clr;
	int		c_clr;
	int		no_nb;
	int		so_nb;
	int		we_nb;
	int		ea_nb;
	int		f_nb;
	int		c_nb;
}				t_data;

typedef struct s_game
{
	t_data		data;
	t_player 	*player;
	t_frame		*frame;
	t_frame		*textures[4];
	void		*mlx;
	void		*win;
}				t_game;

//			CUB3D

void	setup_game(char *file);

//			PARSING

int		ft_check_arg(char *str);
int		ft_read_file(t_game *game, char *file);
int		ft_create_tab(t_game *game);
int		ft_setup_data(t_game *game);
int		ft_fill_color(char *str, int *nb);
int		check_color_str(char *str);
char		*ft_fill_path(t_game *game, char *str, int *nb);
int		ft_get_maxlen(char **tab);
int		ft_check_lim(char **map);
char		**ft_create_map(char **tab, int max);
int		ft_check_map(char **map, int max);
int		ft_isspace(int c);
int		ft_isstart(int c);
char		*ft_strdup_max(char *s, int max);
int		ft_check_empty(char *str);
int		ft_strcmp(char *s1, char *s2);
//			FREE_PRINT

void	ft_print_error(char *file, char *str);
void	ft_clear_tab(char ***tab, int pos);
void	ft_clear_parse(t_game *game, char *str);
void	ft_clear_all(t_game *game, char *str);
void	ft_exit_err(char *file, char *str, int ex);

// Display functions !

void	draw_line(t_frame frame, double x0, double y0, double x1, double y1);
void	draw_square(int x, int y, int sizex, int sizey, int color, t_frame frame);
void	draw_player(t_player player, t_frame frame);
void	display_frame(t_game game);
void	draw_stripe(t_game game, int x, int draw_start, int draw_end, int text_x, int line_height);
void	my_mlx_pixel_put(t_frame *data, int x, int y, int color);

// Divers

void	raycasting(t_game game);
uint	get_pixel_img(t_frame *data, int x, int y);

// Event

int	key_press(int keycode, t_game *vars);

#endif
