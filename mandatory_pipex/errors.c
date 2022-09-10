/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:13:43 by asokolov          #+#    #+#             */
/*   Updated: 2022/06/16 00:19:48 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_errors(int argc, char **argv, char **envp)
{
	if (!argv || !envp || argc < 1)
		exit(1);
	if (argc != 5)
	{
		ft_putstr_fd("\nExpected \"./pipex file1 cmd1 cmd2.. file2\"\n\n", 2);
		exit(1);
	}
}

void	errors(int error, char *av)
{
	if (error == 127)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(av, 2);
		write(2, "\n", 1);
	}
	else if (error == 13)
	{
		perror(av);
		exit(1);
	}
	else if (error == 2)
	{
		perror(av);
		exit(0);
	}
	else if (error != 0)
	{
		perror(NULL);
		exit(error);
	}
}
