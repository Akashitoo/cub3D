/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:37:55 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/26 18:07:05 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void	*destination, const void *source, size_t size)
{
	char	*dest;
	char	*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	src = (void *)source;
	dest = destination;
	while (size--)
	{
		*dest++ = *src++;
	}
	return (destination);
}
