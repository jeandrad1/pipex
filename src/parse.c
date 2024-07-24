/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:59:27 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 11:56:16 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Check if PATH is set and set it if not
static void	check_and_set_env(char **env)
{
	int	path_found;

	path_found = 0;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path_found = 1;
			break ;
		}
		env++;
	}
	if (!path_found)
	{
		perror("Error: PATH not set");
		exit(EXIT_FAILURE);
	}
}

static char	**split_command(const char *command)
{
	char	**args;
	char	*cmd_copy;
	char	*token;
	int		count;

	args = NULL;
	cmd_copy = ft_strdup(command);
	token = ft_strtok(cmd_copy, " ");
	count = 0;
	while (token)
	{
		args = realloc(args, sizeof(char *) * (count + 1));
		args[count] = ft_strdup(token);
		count++;
		token = ft_strtok(NULL, " ");
	}
	args = realloc(args, sizeof(char *) * (count + 1));
	args[count] = NULL;
	free(cmd_copy);
	return (args);
}

void	ft_parse(int argc, char **argv, t_args *pipex)
{
	int	infile_fd;

	if (argc != 5)
		ft_exit(pipex, "Usage: ./pipex infile command1 command2 outfile",
			EXIT_FAILURE);
	pipex->infile = argv[1];
	pipex->cmd1 = split_command(argv[2]);
	pipex->cmd2 = split_command(argv[3]);
	pipex->outfile = argv[4];
	infile_fd = open(pipex->infile, O_RDONLY);
	if (infile_fd == -1)
		ft_exit(pipex, "Error: Unable to open infile", EXIT_FAILURE);
	close(infile_fd);
	check_and_set_env(pipex->env);
}
