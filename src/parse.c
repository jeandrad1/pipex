/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:59:27 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/27 13:21:11 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Check if the string is empty or contains only spaces
static int	check_void(const char *str)
{
	if (str == NULL)
		return (1);
	while (*str)
	{
		if (!ft_isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

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
// It uses tokenize_command to split the command by spaces
// And reallocates the array of strings to store each token
// It returns the array of strings
static char	**split_command(const char *command)
{
	char	**args;

	args = ft_split(command, ' ');
	return (args);
}

// Parse the arguments
// Uses the split_command function to split the commands
// And checks if the infile and outfile can be opened
// Check the environment variables
void	ft_parse(int argc, char **argv, t_args *pipex)
{
	int	infile_fd;
	int	i;

	i = 0;
	if (argc != 5)
		ft_exit(pipex, "Error: invalid number of arguments", EXIT_FAILURE);
	if (check_void(argv[2]) || check_void(argv[3]))
		ft_exit(pipex, "Error: command arguments cannot be empty or whitespace",
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
