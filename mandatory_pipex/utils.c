/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:35:24 by asokolov          #+#    #+#             */
/*   Updated: 2022/06/17 00:44:41 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_val(t_val *val)
{
	val->ac = 0;
	val->av = NULL;
	val->evp = NULL;
	val->pipe_fd = NULL;
	val->pids = NULL;
	val->path = NULL;
	val->cmd_with_options = NULL;
	val->cmds_nbr = 0;
	val->pid = 0;
	val->file1 = 0;
	val->file2 = 0;
}

void	malloc_val(t_val *val, int argc, char **argv, char **envp)
{
	val->ac = argc;
	val->av = argv;
	val->evp = envp;
	open_files(val);
	val->pipe_fd = (int *)malloc(sizeof(int *) * 2);
	if (!val->pipe_fd)
		exit(1);
	val->pids = (int *)malloc(sizeof(int *) * 2);
	if (!val->pids)
		exit(1);
	val->path = NULL;
	val->cmd_with_options = NULL;
	val->cmds_nbr = 2;
	val->pid = 0;
}

void	free_char_of_chars(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}

void	close_standard_fds(void)
{
	int	i;

	i = 2;
	while (i != -1)
	{
		if (close(i) < 0)
			errors(errno, NULL);
		i--;
	}
}
