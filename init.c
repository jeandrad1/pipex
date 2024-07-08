/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:51 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 12:58:05 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(int argc, char **argv, t_args pipex)
{
	pipex.cmd = NULL;
	pipex.infile = NULL;
	pipex.outfile = NULL;
	pipex.infile_fd = -1;
	pipex.outfile_fd = -1;
	pipex.pipe_fd[0] = -1;
	pipex.pipe_fd[1] = -1;
	pipex.pid = -1;
	return (pipex);
}
