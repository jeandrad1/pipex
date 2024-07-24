/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:07:10 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 17:32:01 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Function to handle the child process for the first command
// Uses dup2 to redirect the input and output of the command
// Closes the file descriptors and executes the command 
static void	handle_child1(t_args *pipex, int pipe_fd[2])
{
	int	infile_fd;

	infile_fd = open(pipex->infile, O_RDONLY);
	if (infile_fd == -1)
		ft_exit(pipex, "Error: Unable to open infile in child process",
			EXIT_FAILURE);
	dup2(infile_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(infile_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execvp(pipex->cmd1[0], pipex->cmd1);
	ft_exit(pipex, "Error: execvp failed for cmd1", 127);
}

// Function to handle the child process for the second command
// Uses dup2 to redirect the input and output of the command
// Closes the file descriptors and executes the command 
static void	handle_child2(t_args *pipex, int pipe_fd[2])
{
	int	outfile_fd;

	outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		ft_exit(pipex, "Error: Unable to open outfile in child process",
			EXIT_FAILURE);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execvp(pipex->cmd2[0], pipex->cmd2);
	ft_exit(pipex, "Error: execvp failed for cmd2", 127);
}

// Function to handle the parent process
// Closes the file descriptors and waits for the child processes to finish
// If the child processes fail it displays an error message and exits
static void	handle_parent(t_args *pipex, int pipe_fd[2], pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (waitpid(pid1, &status1, 0) == -1)
		ft_exit(pipex, "Error: waitpid failed for cmd1", 127);
	if (waitpid(pid2, &status2, 0) == -1)
		ft_exit(pipex, "Error: waitpid failed for cmd2", 127);
	if (WEXITSTATUS(status2) != 0 || WEXITSTATUS(status1) != 0)
		ft_exit(pipex, "Error ", 127);
}

// Function to execute the commands
// Creates a pipe and forks two child processes
// The child proocesses are concurrent and execute the commands
// The parent process waits for the child processes to finish
void	ft_exec_cmd(t_args *pipex)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipe_fd) == -1)
		ft_exit(pipex, "Error: Unable to create pipe", 127);
	pid1 = fork();
	if (pid1 == -1)
		ft_exit(pipex, "Error: Unable to fork process for cmd1", 127);
	else if (pid1 == 0)
		handle_child1(pipex, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_exit(pipex, "Error: Unable to fork process for cmd2", 127);
	else if (pid2 == 0)
		handle_child2(pipex, pipe_fd);
	handle_parent(pipex, pipe_fd, pid1, pid2);
}
