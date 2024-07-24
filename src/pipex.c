/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 14:41:04 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Main function of the program
// This function initializes the pipex structure, 
//parses the arguments,
// executes the commands and frees the structure
int	main(int argc, char **argv, char **env)
{
	t_args	pipex;

	pipex.env = env;
	printf("memset OK\n");
	ft_init_pipex(&pipex);
	printf("init OK\n");
	ft_parse(argc, argv, &pipex);
	printf("parse OK\n");
	ft_exec_cmd(&pipex);
	printf("exec OK\n");
	ft_free_pipex(&pipex);
	printf("free OK\n");
	printf("EXIT_SUCCESS\n");
	return (EXIT_SUCCESS);
}
