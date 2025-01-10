/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:35:23 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/26 18:11:13 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > ((size_t) -1 / size))
		return (NULL);
	mem = (void *)malloc(size * nmemb);
	if (!mem)
		return (0);
	while (i < size * nmemb)
	{
		*(unsigned char *)(mem + i) = 0;
		i++;
	}
	return (mem);
}
