/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 11:43:29 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	return (EXIT_SUCCESS);
}
