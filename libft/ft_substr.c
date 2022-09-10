/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 05:54:33 by asokolov          #+#    #+#             */
/*   Updated: 2021/12/15 19:44:42 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, size_t len, unsigned int start)
{
	size_t	i;

	i = 0;
	while (i < len && s[start])
	{
		i++;
		start++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (!s)
		return ("");
	if (start >= (unsigned int)ft_strlen(s))
	{
		dest = (char *)malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	dest = (char *)malloc(ft_len(s, len, start) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (i < len && s[start])
	{	
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
