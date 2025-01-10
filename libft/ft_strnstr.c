/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:52:20 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/30 14:47:30 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	s3 = (char *)s1;
	i = 0;
	while (i < len && s3[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j] && i + j < len)
		{
			j++;
		}
		if (j == ft_strlen(s2))
			return (&s3[i]);
		i++;
	}
	return (0);
}
