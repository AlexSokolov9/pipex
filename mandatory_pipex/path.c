/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:59:15 by asokolov          #+#    #+#             */
/*   Updated: 2022/06/15 21:31:27 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_t_pa(t_pa *pa)
{
	pa->path = NULL;
	pa->dirs = NULL;
	pa->dir_with_cmd = NULL;
	pa->tmp = NULL;
	pa->i = 0;
	pa->find_path = 0;
}

/* 
1 == PATH=/mnt/nfs/homes/asokolov/bin:/mnt/nfs/homes/asokolov/bin:......
2 == remove PATH= == /mnt/nfs/homes/asokolov/bin:/mnt/nfs/homes/asokolov/bin:....
3 == separate ..... == /mnt/nfs/homes/asokolov/bin
4 == add surdir ... == /mnt/nfs/homes/asokolov/bin/
5 == add_cmd ...... == /mnt/nfs/homes/asokolov/bin/cat
6 == access if exists and can be executed
*/

void	add_subdir(t_pa pa)
{
	pa.i = 0;
	while (pa.dirs[pa.i])
	{
		pa.tmp = pa.dirs[pa.i];
		pa.dirs[pa.i] = ft_strjoin(pa.dirs[pa.i], "/");
		free(pa.tmp);
		pa.i++;
	}
}

char	*access_cmd(t_pa pa, char *cmd)
{
	pa.i = 0;
	while (pa.dirs[pa.i])
	{
		pa.dir_with_cmd = ft_strjoin(pa.dirs[pa.i], cmd);
		pa.find_path = access(pa.dir_with_cmd, F_OK | X_OK);
		if (pa.find_path == 0)
		{
			free_char_of_chars(pa.dirs);
			free(pa.path);
			return (pa.dir_with_cmd);
		}
		free(pa.dir_with_cmd);
		pa.i++;
	}
	if (pa.find_path == -1)
	{
		errors(127, cmd);
		free_char_of_chars(pa.dirs);
		free(pa.path);
		return (NULL);
	}
	free_char_of_chars(pa.dirs);
	return (NULL);
}

char	*get_cmd_path(t_val val, char *cmd)
{
	t_pa	pa;

	init_t_pa(&pa);
	while (val.evp[pa.i])
	{
		pa.path = ft_strnstr(val.evp[pa.i], "PATH=", 5);
		if (pa.path)
		{
			pa.path = ft_substr(val.evp[pa.i], 5, ft_strlen(val.evp[pa.i]));
			if (!pa.path)
				return (NULL);
			break ;
		}
		pa.i++;
	}
	pa.dirs = ft_split(pa.path, ':');
	if (!pa.dirs)
	{
		free(pa.path);
		return (NULL);
	}
	add_subdir(pa);
	return (access_cmd(pa, cmd));
}
