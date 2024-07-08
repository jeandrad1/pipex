/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 15:12:03 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Main function
int	main(int argc, char **argv)
{
	t_args	pipex;

	ft_init_pipex(argc, argv, pipex);
	ft_parse(argc, argv, pipex);
	ft_split_cmd(pipex);
	ft_exec_cmd(pipex);
	free_pipe(pipex);

	return (EXIT_SUCCESS);
}
