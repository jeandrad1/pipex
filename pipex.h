/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:14:07 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 13:01:36 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

typedef struct s_args
{
	char	**cmd;
	char	*infile;
	char	*outfile;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	int		pid;
}	t_args;

void	ft_init_pipex(int argc, char **argv, t_args pipex);
void	ft_parse(int argc, char **argv, t_args pipex);
void	ft_split_cmd();
void	ft_exec_cmd();
void	exit_error(int error, int is_exit);
void	init_pipex();

