/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:59:19 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/06 15:00:51 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*x;
	size_t			i;

	x = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (x[i] == (unsigned char)c)
			return ((void *) x + i);
		i++;
	}
	return (NULL);
}
