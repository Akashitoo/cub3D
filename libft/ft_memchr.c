/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:17:25 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/26 04:18:49 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	const char	*src;

	src = memoryBlock;
	while (size--)
	{
		if (*src == (char)searchedChar)
			return ((void *)src);
		src++;
	}
	return (0);
}
