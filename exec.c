/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:07:10 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 15:10:23 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_cmd(t_args s_pipex)
{
	s_pipex.pid = fork();
	if (s_pipex.pid == -1)
		exit_error(FORK_ERROR, 1);
	if (s_pipex.pid == 0)
	{
		if (s_pipex.infile_fd != -1)
		{
			if (dup2(s_pipex.infile_fd, STDIN_FILENO) == -1)
				exit_error(DUP2_ERROR, 1);
		}
		if (s_pipex.outfile_fd != -1)
		{
			if (dup2(s_pipex.outfile_fd, STDOUT_FILENO) == -1)
				exit_error(DUP2_ERROR, 1);
		}
		if (s_pipex.pipe_fd[1] != -1)
		{
			if (dup2(s_pipex.pipe_fd[1], STDOUT_FILENO) == -1)
				exit_error(DUP2_ERROR, 1);
		}
		if (s_pipex.pipe_fd[0] != -1)
		{
			if (dup2(s_pipex.pipe_fd[0], STDIN_FILENO) == -1)
				exit_error(DUP2_ERROR, 1);
		}
		execve(s_pipex.cmd[0], s_pipex.cmd, NULL);
		exit_error(EXEC_ERROR, 1);
	}
	else
		wait(NULL);
}
