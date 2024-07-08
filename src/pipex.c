/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 15:30:11 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
