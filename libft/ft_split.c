/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:15:51 by abalasub          #+#    #+#             */
/*   Updated: 2024/05/12 21:22:50 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_mem(char **tab_to_free)
{
	int	i;

	i = 0;
	while (tab_to_free[i])
	{
		free(tab_to_free[i]);
		i++;
	}
	free(tab_to_free);
}

static int	tabsize(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static void	triinit(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

static char	**memelt(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**tab;

	tab = malloc(sizeof(char *) * (tabsize(s, c) + 1));
	if (!tab)
		return (0);
	triinit(&i, &j, &count);
	while (s[i])
	{
		while (s[i + j] && s[i + j] != c)
			j++;
		i += j;
		if (j > 0)
		{
			tab[count++] = malloc(sizeof(char) * (j + 1));
			if (!tab[count - 1])
				return (free_mem(tab), NULL);
			j = 0;
		}
		if (s[i])
			i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = memelt(s, c);
	if (!tab || !s || !c)
		return (0);
	triinit(&i, &j, &k);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			tab[j][k++] = s[i];
			tab[j++][k] = '\0';
			k = 0;
		}
		else if (s[i] != c)
			tab[j][k++] = s[i];
		i++;
	}
	tab[j] = 0;
	if (!tab || !tab[0])
		return (free_mem(tab), NULL);
	return (tab);
}
