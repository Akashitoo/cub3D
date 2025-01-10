/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:11:50 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/24 04:02:52 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	int	i;

	if (!length)
		return (length);
	i = 0;
	while (first[i] && second[i] && first[i] == second[i] && length - 1)
	{
		i++;
		length--;
	}
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}

	/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_strncmp("test\200", "test\0", 6));
}*/
