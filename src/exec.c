/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:07:10 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/20 12:41:18 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exec_cmd(t_args pipex)
{
	pipex.pid = fork();
	if (pipex.pid == -1)
		exit_error(FORK_ERROR, 1, &pipex, 1);
		
	if (pipex.pid == 0)
	{
		if (pipex.infile_fd != -1)
		{
			if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex, 1);
		}
		if (pipex.outfile_fd != -1)
		{
			if (dup2(pipex.outfile_fd, STDOUT_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex, 1);
		}
		if (pipex.pipe_fd[1] != -1)
		{
			if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex, 1);
		}
		if (pipex.pipe_fd[0] != -1)
		{
			if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex, 1);
		}
		execve(pipex.cmd[0], pipex.cmd, NULL);
		
		exit_error(EXEC_ERROR, 1, &pipex, 1);
	}
	else
		wait(NULL);
}
