/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:27:30 by sryou             #+#    #+#             */
/*   Updated: 2022/09/04 22:16:54 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"

# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	char	**argv[2];
	char	**env;
	char	**path;
	char	*exec[2];
	char	*shell;
	char	*current_path;
	char	*read_file;
	char	*write_file;
	int		pipe_fd[2];
	int		read_fd;
	int		write_fd;
}	t_data;

void	throw_error(t_data *data, char *message);
void	puterrors(char *message1, char *message2);
void	quit(t_data *data, int code);
void	fileopen(t_data *data);
void	pipeopen(t_data *data);
void	fileclose(t_data *data);
t_data	*parse(char **argv, char **env);
void	parse_excution(t_data *data, char *exec, int order);
void	parse_check(t_data *data);

#endif
