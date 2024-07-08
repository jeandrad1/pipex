/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:51 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 16:34:49 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_pipex(t_args pipex)
{
	pipex.cmd = NULL;
	pipex.infile = NULL;
	pipex.outfile = NULL;
	pipex.infile_fd = -1;
	pipex.outfile_fd = -1;
	pipex.pipe_fd[0] = -1;
	pipex.pipe_fd[1] = -1;
	pipex.pid = -1;
	return ;
}
