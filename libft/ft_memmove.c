/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:51:31 by asokolov          #+#    #+#             */
/*   Updated: 2021/12/18 22:47:26 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*s;

	i = len;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d > s)
	{
		while (i--)
		{
			d[i] = s[i];
		}
		return (d);
	}
	return (ft_memcpy(dst, src, len));
}
