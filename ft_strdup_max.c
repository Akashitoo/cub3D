/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:15:26 by mqwa              #+#    #+#             */
/*   Updated: 2025/01/22 01:43:44 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strdup_max(char *s, int max)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (max + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	while (i < max)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = 0;
	return (str);
}
