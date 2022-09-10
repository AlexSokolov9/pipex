/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:24:10 by asokolov          #+#    #+#             */
/*   Updated: 2022/06/17 03:43:38 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_all_files_and_pipes_fds(t_val val)
{
	int	i;

	i = 0;
	if (close(val.file1) < 0)
		errors(errno, NULL);
	if (close(val.file2) < 0)
		errors(errno, NULL);
	while (i < (val.cmds_nbr - 1) * 2)
	{
		if (close(val.pipe_fd[i]) < 0)
			errors(errno, NULL);
		i++;
	}
}

void	wait_for_all_pids(t_val val)
{
	int	i;

	i = -1;
	while (++i != val.pid)
	{
		if (!val.pid)
			exit(127);
		if (waitpid(-1, NULL, 0) < 0)
		{
			free(val.pids);
			free(val.pipe_fd);
			exit(1);
		}
	}
}

void	create_pipes(t_val val)
{
	int	i;

	i = -1;
	while (++i < val.cmds_nbr - 1)
		if (pipe(val.pipe_fd + (2 * i)) < 0)
			errors(errno, NULL);
}

void	dup2_right_pipes(t_val val)
{
	if (val.pid == 0)
	{
		if (dup2(val.file1, STDIN_FILENO) < 0)
			errors(errno, NULL);
		if (dup2(val.pipe_fd[1], STDOUT_FILENO) < 0)
			errors(errno, NULL);
	}
	else if (val.pid > 0 && val.pid < val.cmds_nbr - 1)
	{
		if (dup2(val.pipe_fd[2 * val.pid - 2], STDIN_FILENO) < 0)
			errors(errno, NULL);
		if (dup2(val.pipe_fd[2 * val.pid + 1], STDOUT_FILENO) < 0)
			errors(errno, NULL);
	}
	else if (val.pid == val.cmds_nbr - 1)
	{
		if (dup2(val.pipe_fd[2 * val.pid - 2], STDIN_FILENO) < 0)
			errors(errno, NULL);
		if (dup2(val.file2, STDOUT_FILENO) < 0)
			errors(errno, NULL);
	}
}

void	process(t_val val, int i)
{
	val.cmd_with_options = ft_split(val.av[i], ' ');
	val.path = get_cmd_path(val, val.cmd_with_options[0]);
	if (val.path != NULL)
	{
		val.pids[val.pid] = fork();
		if (val.pids[val.pid] == 0)
		{
			dup2_right_pipes(val);
			close_all_files_and_pipes_fds(val);
			if (execve(val.path, val.cmd_with_options, val.evp) < 0)
				errors(errno, NULL);
		}
	}
	free(val.path);
	free_char_of_chars(val.cmd_with_options);
}
