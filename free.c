/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:24 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 15:23:22 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipex(t_args pipex)
{
	int	i;

	i = 0;
	if (pipex.cmd)
	{
		while (pipex.cmd[i])
		{
			free(pipex.cmd[i]);
			i++;
		}
		free(pipex.cmd);
	}
	if (pipex.infile)
		free(pipex.infile);
	if (pipex.outfile)
		free(pipex.outfile);
	if (pipex.infile_fd != -1)
		close(pipex.infile_fd);
	if (pipex.outfile_fd != -1)
		close(pipex.outfile_fd);
	if (pipex.pipe_fd[0] != -1)
		close(pipex.pipe_fd[0]);
	if (pipex.pipe_fd[1] != -1)
		close(pipex.pipe_fd[1]);
	free(&pipex);
}
