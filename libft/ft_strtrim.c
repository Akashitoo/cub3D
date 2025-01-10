/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:42:56 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/30 14:44:49 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	first_occ(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (is_set(set, s1[i]))
		i++;
	return (i);
}

static int	last_occ(char const *s1, char const *set)
{
	int	j;

	j = ft_strlen(s1);
	while (is_set(set, s1[j - 1]))
		j--;
	return (j);
}

static int	count_size(char const *s1, char const *set)
{
	return (last_occ(s1, set) - first_occ(s1, set));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (count_size(s1, set) < 0)
	{
		str = (char *) malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = (char *) malloc(sizeof(char) * (count_size(s1, set) + 1));
	if (!str)
		return (0);
	i = first_occ(s1, set);
	j = 0;
	while (i < last_occ(s1, set))
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
