/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:16:00 by asokolov          #+#    #+#             */
/*   Updated: 2022/06/16 00:27:35 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_val	val;
	int		i;

	input_errors(argc, argv, envp);
	i = 2;
	init_val(&val);
	malloc_val(&val, argc, argv, envp);
	create_pipes(val);
	while (val.pid < val.cmds_nbr)
	{
		process(val, i);
		val.pid++;
		i++;
	}
	close_all_files_and_pipes_fds(val);
	wait_for_all_pids(val);
	free(val.pids);
	free(val.pipe_fd);
	close_standard_fds();
	return (0);
}
