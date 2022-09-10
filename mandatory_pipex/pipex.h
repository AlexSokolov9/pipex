/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:22:46 by asokolov          #+#    #+#             */
/*   Updated: 2022/06/17 00:52:14 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct val
{
	int		ac;
	char	**av;
	char	**evp;
	int		*pipe_fd;
	int		*pids;
	char	*path;
	char	**cmd_with_options;
	int		cmds_nbr;
	int		pid;
	int		file1;
	int		file2;

}	t_val;

typedef struct pa
{
	char	*path;
	char	**dirs;
	char	*dir_with_cmd;
	char	*tmp;
	int		i;
	int		find_path;

}	t_pa;

void	init_val(t_val *val);
void	malloc_val(t_val *val, int argc, char **argv, char **envp);
void	open_files(t_val *val);
void	free_char_of_chars(char **strs);
void	input_errors(int argc, char **argv, char **envp);
void	errors(int error, char *av);
void	close_standard_fds(void);
char	*get_cmd_path(t_val val, char *cmd);
void	close_all_files_and_pipes_fds(t_val val);
void	wait_for_all_pids(t_val val);
void	create_pipes(t_val val);
void	dup2_right_pipes(t_val val);
void	process(t_val val, int i);

#endif