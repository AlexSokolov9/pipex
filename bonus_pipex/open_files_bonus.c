/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:52:40 by asokolov          #+#    #+#             */
/*   Updated: 2022/06/17 02:38:25 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_and_read_heredoc(char *heredoc, char *limiter, int tmp_file)
{
	while (42 == 42)
	{
		write(1, "pipe heredoc> ", 14);
		heredoc = get_next_line(0);
		if (!heredoc)
			break ;
		if (((ft_strlen(heredoc) - 1) == ft_strlen(limiter))
			&& (ft_strncmp(heredoc, limiter, ft_strlen(limiter)) == 0))
		{
			free(heredoc);
			break ;
		}
		else
			ft_putstr_fd(heredoc, tmp_file);
		free(heredoc);
	}
}

void	open_heredoc(t_val *val, char *heredoc,	int tmp_file)
{
	tmp_file = open("/tmp/tmp_of_pipex", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (tmp_file < 0)
		perror(val->av[val->ac - 1]);
	print_and_read_heredoc(heredoc, val->av[2], tmp_file);
	val->file1 = open("/tmp/tmp_of_pipex", O_RDONLY);
	if (val->file1 < 0)
		perror(val->av[val->ac - 1]);
	unlink("/tmp/tmp_of_pipex");
	val->file2 = open(val->av[val->ac -1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (val->file2 < 0)
		perror(val->av[val->ac - 1]);
}

void	open_files(t_val *val)
{
	char	*heredoc;
	int		tmp_file;

	heredoc = NULL;
	tmp_file = 0;
	if (ft_strncmp(val->av[1], "here_doc", 8) == 0)
		open_heredoc(val, heredoc, tmp_file);
	else
	{
		val->file1 = open(val->av[1], O_RDONLY);
		if (val->file1 < 0)
			errors(errno, val->av[1]);
		val->file2 = open(val->av[val->ac - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (val->file2 < 0)
			errors(errno, val->av[val->ac - 1]);
	}
}
