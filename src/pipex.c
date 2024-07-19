/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/19 11:27:16 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Main function
int	main(int argc, char **argv)
{
	t_args	pipex;

	ft_memset(&pipex, 0, sizeof(t_args));
	printf("memset OK\n");
	ft_init_pipex(pipex);
	printf("init OK\n");
	ft_parse(argc, argv, pipex);
	printf("parse OK\n");
	ft_split_cmd(pipex);
	printf("split OK\n");
	ft_exec_cmd(pipex);
	printf("exec OK\n");
	ft_free_pipex(pipex);
	printf("free OK\n");

// Return the program
	return (EXIT_SUCCESS);
}
