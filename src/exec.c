/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:07:10 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/19 11:21:01 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exec_cmd(t_args pipex)
{
	//check if the fork is successful
	pipex.pid = fork();
	if (pipex.pid == -1)
		exit_error(FORK_ERROR, 1, &pipex);
		
	//if the fork is successful, check if the child process is running
	if (pipex.pid == 0)
	{
		//check if the input file is valid
		if (pipex.infile_fd != -1)
		{
			//check if the file descriptor is valid
			if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex);
		}
		//check if the output file is valid
		if (pipex.outfile_fd != -1)
		{
			//check if the file descriptor is valid
			if (dup2(pipex.outfile_fd, STDOUT_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex);
		}
		if (pipex.pipe_fd[1] != -1)
		{
			//check if the file descriptor is valid
			if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex);
		}
		if (pipex.pipe_fd[0] != -1)
		{
			//check if the file descriptor is valid
			if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex);
		}
		//check if the command is valid and execute it
		execve(pipex.cmd[0], pipex.cmd, NULL);
		
		//if the command is not valid, exit the program
		exit_error(EXEC_ERROR, 1, &pipex);
	}
	else
		//if the child process is not running, wait for it to finish
		wait(NULL);
}
