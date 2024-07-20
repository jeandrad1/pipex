/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:24 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/20 13:01:19 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_pipex(t_args pipex)
{
	int	i;

	i = 0;
	if (pipex.cmd1)
		free(pipex.cmd1);
	if (pipex.cmd2)
		free(pipex.cmd2);
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
}
