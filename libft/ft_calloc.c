/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:01:14 by asokolov          #+#    #+#             */
/*   Updated: 2021/12/05 22:43:29 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = (char *)malloc(count * size);
	if (!dest)
		return (NULL);
	ft_memset(dest, '\0', (count * size));
	return ((void *)(dest));
}
