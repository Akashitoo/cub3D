/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:37:43 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/26 18:10:08 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (dst[len])
		len++;
	i = 0;
	if (size)
	{
		while (len < size - 1 && src[i])
		{
			dst[len] = src[i];
			len++;
			i++;
		}
		dst[len] = '\0';
	}
	while (src[i])
	{
		len++;
		i++;
	}
	return (len);
}
