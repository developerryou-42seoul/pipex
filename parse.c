/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:28:30 by sryou             #+#    #+#             */
/*   Updated: 2022/09/04 22:16:49 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_check(t_data *data)
{
	int	idx;
	int	flag;

	flag = 0;
	idx = -1;
	while (++idx < 2)
	{
		if (access(data->exec[idx], X_OK) != 0)
		{
			if (ft_strncmp(data->exec[idx], "/", 1) != 0 && \
			ft_strncmp(data->exec[idx], "./", 2) != 0 && \
			ft_strncmp(data->exec[idx], "../", 3) != 0)
				puterrors(strerror(errno), data->exec[idx]);
			else
				puterrors("command not found", data->exec[idx]);
			flag = 1;
		}
	}
	if (flag == 1)
		quit(data, 1);
}

void	parse_excution_path(t_data *data, int order)
{
	int		idx;
	char	*temp1;
	char	*temp2;

	idx = 0;
	while (data->path[idx] != 0)
	{
		temp1 = ft_strjoin(data->path[idx], "/");
		if (temp1 == 0)
			throw_error(data, "execution path join error");
		temp2 = ft_strjoin(temp1, data->exec[order]);
		free(temp1);
		if (temp2 == 0)
			throw_error(data, "execution path join error");
		if (access(temp2, X_OK) == 0)
		{
			free(data->exec[order]);
			data->exec[order] = temp2;
			return ;
		}
		free(temp2);
		idx++;
	}
}

void	parse_excution(t_data *data, char *exec, int order)
{
	data->argv[order] = ft_split(exec, ' ');
	if (data->argv[order] == 0)
		throw_error(data, "execution parse error");
	data->exec[order] = data->argv[order][0];
	data->argv[order][0] = ft_strdup(data->current_path);
	if (ft_strncmp(data->exec[order], "/", 1) != 0 && \
		ft_strncmp(data->exec[order], "./", 2) != 0 && \
		ft_strncmp(data->exec[order], "../", 3) != 0)
		parse_excution_path(data, order);
}

t_data	*parse(char **argv, char **env)
{
	t_data	*new_data;
	int		idx;

	new_data = malloc(sizeof(t_data));
	if (new_data == 0)
		throw_error(new_data, "data malloc error");
	ft_memset(new_data, 0, sizeof(t_data));
	idx = 0;
	new_data->env = env;
	while (env[idx] != 0)
	{
		if (ft_strncmp(env[idx], "PATH=", 5) == 0)
			new_data->path = ft_split(env[idx] + 5, ':');
		idx++;
	}
	if (new_data->path == 0)
		throw_error(new_data, "path parse error");
	new_data->current_path = ft_strdup(argv[0]);
	new_data->read_file = ft_strdup(argv[1]);
	new_data->write_file = ft_strdup(argv[4]);
	if (new_data->current_path == 0 || new_data->read_file == 0 || \
		new_data->write_file == 0)
		throw_error(new_data, "argv parse error");
	return (new_data);
}
