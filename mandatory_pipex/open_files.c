/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:52:40 by asokolov          #+#    #+#             */
/*   Updated: 2022/06/16 00:29:52 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_val *val)
{
	val->file1 = open(val->av[1], O_RDONLY);
	if (val->file1 < 0)
		errors(errno, val->av[1]);
	val->file2 = open(val->av[4],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (val->file2 < 0)
		errors(errno, val->av[4]);
}
