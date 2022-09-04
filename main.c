/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:27:07 by sryou             #+#    #+#             */
/*   Updated: 2022/09/04 22:10:57 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	runprocess0(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		throw_error(data, "process create error");
	else if (pid > 0)
	{
		dup2(data->pipe_fd[0], 0);
		close(data->pipe_fd[1]);
		dup2(data->write_fd, 1);
		wait(0);
	}
	else
	{
		dup2(data->read_fd, 0);
		dup2(data->pipe_fd[1], 1);
		close(data->pipe_fd[0]);
		execve(data->exec[0], data->argv[0], data->env);
	}
}

void	runprocess1(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		throw_error(data, "process create error");
	else if (pid > 0)
		wait(0);
	else
		execve(data->exec[1], data->argv[1], data->env);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc == 5)
	{
		data = parse(argv, env);
		fileopen(data);
		parse_excution(data, argv[2], 0);
		parse_excution(data, argv[3], 1);
		parse_check(data);
		pipeopen(data);
		runprocess0(data);
		runprocess1(data);
		fileclose(data);
		quit(data, 0);
	}
}
