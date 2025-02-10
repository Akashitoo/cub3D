/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:38:42 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/21 16:34:45 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_free_return(t_game *game, int fd)
{
	if (game->data.line)
		free(game->data.line);
	close(fd);
	return (0);
}

int	ft_read_file(t_game *game, char *file)
{
	char	buffer[BUFF_SIZE];
	int		fd;
	int		read_bytes;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFF_SIZE - 1);
		if (read_bytes == -1)
			return (ft_free_return(game, fd));
		buffer[read_bytes] = '\0';
		game->data.line = ft_strjoin(game->data.line, buffer);
		if (!game->data.line)
		{
			close(fd);
			ft_exit_err(NULL, "Malloc error\n", 1);
		}
	}
	close(fd);
	return (1);
}
