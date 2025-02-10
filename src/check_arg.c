/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 07:54:08 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/09 18:07:06 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_suf(char *str, int pos)
{
	char	*buf;
	int		i;

	buf = "buc.";
	i = 0;
	while (buf[i])
	{
		if (buf[i] != str[pos])
			return (0);
		i++;
		pos--;
	}
	return (1);
}

int	ft_check_arg(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (0);
	i--;
	if (!ft_check_suf(str, i))
		return (0);
	return (1);
}
