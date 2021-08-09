/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:34:44 by abouhlel          #+#    #+#             */
/*   Updated: 2021/04/07 15:44:39 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstr;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
	{
		newstr = ft_calloc(sizeof(char), 1);
		if (!newstr)
			return (NULL);
		return (newstr);
	}
	newstr = ft_calloc(sizeof(char), len + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	return (newstr);
}
