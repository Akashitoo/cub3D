/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:17:30 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/21 14:22:28 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	unsigned long	i;
	int				cmp;

	i = 0;
	cmp = 0;
	while (i < size)
	{
		i++;
		cmp = *(unsigned char *)pointer1++ - *(unsigned char *)pointer2++;
		if (cmp)
			return (cmp);
	}
	return (0);
}
