/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 18:10:01 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Main function
int	main(int argc, char **argv)
{
	t_args	pipex;

// Initialize the structure in order to avoid garbage values
	ft_memset(&pipex, 0, sizeof(t_args));
	printf("memset OK\n");

// Initialize the structure
	ft_init_pipex(pipex);
	printf("init OK\n");

// Parse the arguments
	ft_parse(argc, argv, pipex);
	printf("parse OK\n");

// Split the command
	ft_split_cmd(pipex);
	printf("split OK\n");

// Execute the command
	ft_exec_cmd(pipex);
	printf("exec OK\n");

// Free the structure
	ft_free_pipex(pipex);
	printf("free OK\n");

// Return the program
	return (EXIT_SUCCESS);
}
