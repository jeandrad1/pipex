/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:15:28 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/26 11:18:35 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Function to allocate memory and copy token
static void	allocate_and_copy_token(char ***args, int count, const char *token)
{
	int	i;

	*args = allocate_args(*args, count);
	(*args)[count] = ft_strdup(token);
	if (!(*args)[count])
	{
		i = 0;
		while (i < count)
		{
			free((*args)[i]);
			i++;
		}
		free(*args);
		perror("Error: memory allocation failed");
		exit(EXIT_FAILURE);
	}
}

// Function to handle memory allocation and error checking
char	**allocate_args(char **args, int count)
{
	int		i;
	char	**new_args;

	new_args = ft_realloc(args, sizeof(char *) * (count + 1));
	if (!new_args || new_args == NULL)
	{
		i = 0;
		while (i < count)
		{
			free(args[i]);
			i++;
		}
		free(args);
		perror("Error: memory allocation failed");
		exit(EXIT_FAILURE);
	}
	return (new_args);
}

// Function to tokenize the command string
char	**tokenize_command(const char *command, int *count)
{
	char	**args;
	char	*cmd_copy;
	char	*token;

	args = NULL;
	cmd_copy = ft_strdup(command);
	if (cmd_copy == NULL)
	{
		perror("Error: empty command");
		exit(EXIT_FAILURE);
	}
	token = ft_strtok(cmd_copy, " ");
	*count = 0;
	while (token)
	{
		allocate_and_copy_token(&args, *count, token);
		(*count)++;
		token = ft_strtok(NULL, " ");
	}
	free(cmd_copy);
	return (args);
}
