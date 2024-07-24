/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 15:55:59 by jeandrad         ###   ########.fr       */
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
	ft_init_pipex(&pipex);
	ft_parse(argc, argv, &pipex);
	ft_exec_cmd(&pipex);
	ft_free_pipex(&pipex);
	return (EXIT_SUCCESS);
}
