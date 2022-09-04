/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:24:08 by sryou             #+#    #+#             */
/*   Updated: 2022/09/04 22:38:13 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	puterrors(char *message1, char *message2)
{
	ft_putstr_fd("pipex: ", 2);
	if (65 <= message1[0] && message1[0] <= 90)
	{
		ft_putchar_fd(message1[0] + 32, 2);
		ft_putstr_fd(message1 + 1, 2);
	}
	else
		ft_putstr_fd(message1, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(message2, 2);
}

void	throw_error(t_data *data, char *message)
{
	ft_putstr_fd("pipex: ", 2);
	if (65 <= message[0] && message[0] <= 90)
	{
		ft_putchar_fd(message[0] + 32, 2);
		ft_putendl_fd(message + 1, 2);
	}
	else
		ft_putendl_fd(message, 2);
	quit(data, 1);
}

void	free_strptr(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx] != 0)
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

void	free_data(t_data *data)
{
	if (data != 0)
	{
		if (data->argv[0] != 0)
			free_strptr(data->argv[0]);
		if (data->argv[1] != 0)
			free_strptr(data->argv[1]);
		if (data->exec[0] != 0)
			free(data->exec[0]);
		if (data->exec[1] != 0)
			free(data->exec[1]);
		if (data->path != 0)
			free_strptr(data->path);
		if (data->current_path != 0)
			free(data->current_path);
		if (data->read_file != 0)
			free(data->read_file);
		if (data->write_file != 0)
			free(data->write_file);
		free(data);
	}
}

void	quit(t_data *data, int code)
{
	free_data(data);
	exit(code);
}
