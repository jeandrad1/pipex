/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:14:07 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 15:00:38 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

#define NOTHING 0
#define ARG_ERROR 1
#define CMD_ERROR 2
#define INFILE_ERROR 3
#define OUTFILE_ERROR 4	
#define PIPE_ERROR 5
#define PIPEX_FILE_ERROR 6
#define FORK_ERROR 7
#define DUP2_ERROR 8
#define EXEC_ERROR 9

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
void	ft_split_cmd(t_args pipex);
void	ft_exec_cmd(t_args pipex);
void	exit_error(int error, int is_exit);

