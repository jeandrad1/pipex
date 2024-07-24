/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:59:27 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 14:54:56 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Check if PATH is set and set it if not it displays an error message and exits
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

// Split the command into an array of strings
//It uses strtok to split the command by spaces
//And reallocates the array of strings to store each token
//It returns the array of strings
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
		args = ft_realloc(args, sizeof(char *) * (count + 1));
		args[count] = ft_strdup(token);
		count++;
		token = ft_strtok(NULL, " ");
	}
	args = ft_realloc(args, sizeof(char *) * (count + 1));
	args[count] = NULL;
	free(cmd_copy);
	return (args);
}

// Parse the arguments
// Uses the split_command function to split the commands
// And checks if the infile and outfile can be opened
// Check the environment variables
void	ft_parse(int argc, char **argv, t_args *pipex)
{
	int	infile_fd;

	if (argc != 5)
		ft_exit(pipex, "Error: invalid number of arguments", EXIT_FAILURE);
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
