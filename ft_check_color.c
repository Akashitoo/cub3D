/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:47:45 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/21 13:48:40 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_sizes(char *str, int pos)
{
	int	count;

	count = 0;
	while (str[pos] && !ft_isspace(str[pos]))
	{
		if (ft_isdigit(str[pos]))
			count++;
		if (count == 0 || count > 3)
			return (0);
		if (str[pos] == ',')
			count = 0;
		if (str[pos] == ',' && !str[pos + 1])
			return (0);
		pos++;
	}
	return (1);
}

static int	ft_count_comma(char *str, int pos)
{
	int	count;

	count = 0;
	while (str[pos] && !ft_isspace(str[pos]))
	{
		if (str[pos] == ',')
			count++;
		pos++;
	}
	return (count);
}

static int	ft_only_digits(char *str, int pos)
{
	if (ft_count_comma(str, pos) != 2)
		return (0);
	while (str[pos] && !ft_isspace(str[pos]))
	{
		if (!ft_isdigit(str[pos]) && str[pos] != ',')
			return (0);
		pos++;
	}
	return (1);
}

int	check_color_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!ft_only_digits(str, i))
		return (0);
	if (!ft_check_sizes(str, i))
		return (0);
	return (1);
}
