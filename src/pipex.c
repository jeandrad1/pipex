/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 16:35:10 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Main function
int	main(int argc, char **argv)
{
	t_args	pipex;

	ft_memset(&pipex, 0, sizeof(t_args));
	ft_init_pipex(pipex);
	ft_parse(argc, argv, pipex);
	ft_split_cmd(pipex);
	ft_exec_cmd(pipex);
	ft_free_pipex(pipex);

	return (EXIT_SUCCESS);
}
