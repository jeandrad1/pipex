/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:14:07 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 14:51:43 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

// Error codes
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

// Structure to store the arguments
typedef struct s_args
{
	char	**cmd1;
	char	**cmd2;
	char	*infile;
	char	*outfile;
	char	**env;
}	t_args;

void	ft_init_pipex(t_args *pipex);
void	ft_parse(int argc, char **argv, t_args *pipex);
void	ft_split_cmd(t_args *pipex);
void	ft_exec_cmd(t_args *pipex);
void	ft_exit(t_args *pipex, const char *error_message, int exit_code);
void	ft_free_pipex(t_args *pipex);