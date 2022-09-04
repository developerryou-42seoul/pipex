/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:12 by sryou             #+#    #+#             */
/*   Updated: 2022/09/04 22:40:22 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fileopen(t_data *data)
{
	int	flag;

	flag = 0;
	data->read_fd = open(data->read_file, O_RDONLY);
	if (data->read_fd < 0)
	{
		puterrors(strerror(errno), data->read_file);
		flag = 1;
	}
	data->write_fd = open(data->write_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->write_fd < 0)
	{
		puterrors(strerror(errno), data->write_file);
		flag = 1;
	}
	if (flag == 1)
		quit(data, 1);
}

void	pipeopen(t_data *data)
{
	if (pipe(data->pipe_fd) < 0)
		throw_error(data, "pipe create error");
}

void	fileclose(t_data *data)
{
	close(data->read_fd);
	close(data->write_fd);
}
