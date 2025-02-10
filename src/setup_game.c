/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:16:36 by mqwa              #+#    #+#             */
/*   Updated: 2025/02/09 01:58:13 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_data(t_game *game)
{
	game->data.tab = NULL;
	game->data.map = NULL;
	game->data.line = NULL;
	game->data.no_p = NULL;
	game->data.so_p = NULL;
	game->data.we_p = NULL;
	game->data.ea_p = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->data.c_clr = 0;
	game->data.f_clr = 0;
	game->data.no_nb = 0;
	game->data.so_nb = 0;
	game->data.we_nb = 0;
	game->data.ea_nb = 0;
	game->data.c_nb = 0;
	game->data.f_nb = 0;
}

void	setup_game(char *file)
{
	t_game	game;

	if (!ft_check_arg(file))
		ft_exit_err(file, " is not a correct file\n", 1);
	ft_init_data(&game);
	if (!ft_read_file(&game, file))
		ft_exit_err(NULL, "Can't read file\n", 1);
	if (!ft_create_tab(&game))
		ft_exit_err(NULL, "Malloc error\n", 1);
	if (!ft_setup_data(&game))
		ft_clear_parse(&game, "Wrong format in file\n");
	if (!start_game(game))
		ft_clear_all(&game, "minilibX error\n", 1, 0);
}
