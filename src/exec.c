/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:07:10 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/27 16:40:29 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Function to handle the child process for the first command
// Uses dup2 to redirect the input and output of the command
// Closes the file descriptors and executes the command 
// dup2() makes newfd be the copy of oldfd, closing newfd first if necessary,
// but note the following: if oldfd is not a valid file descriptor,
// then the call fails, and newfd is not closed.
// close() closes a file descriptor, so that it no longer refers to any file and may be reused.
// execvp() executes the program pointed to by file, searching for the program in the directories
// listed in the PATH environment variable.
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
	ft_exit(pipex, "", EXEC_ERROR);
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
	if (execvp(pipex->cmd2[0], pipex->cmd2) == -1)
		ft_exit(pipex, "", EXEC_ERROR);
}

// Function to handle the parent process
// Closes the file descriptors and waits for the child processes to finish
// If the child processes fail it displays an error message and exits
// WEXITSTATUS returns the exit status of the child
// WIFEXITED returns true if the child terminated normally
// waitpid() suspends the calling process until a child specified by pid argument has changed state
static void	handle_parent(t_args *pipex, int pipe_fd[2], pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (waitpid(pid1, &status1, 0) == -1)
		ft_exit(pipex, "Error: waitpid failed for cmd1", EXEC_ERROR);
	if (waitpid(pid2, &status2, 0) == -1)
		ft_exit(pipex, "Error: waitpid failed for cmd2", EXEC_ERROR);
	if (WEXITSTATUS(status1) == EXEC_ERROR
		&& WEXITSTATUS(status2) == EXEC_ERROR)
		ft_exit(pipex, "Command 1 error", EXEC_ERROR);
	else if (WEXITSTATUS(status2) == EXEC_ERROR)
		ft_exit(pipex, "Command 2 error", EXEC_ERROR);
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
		ft_exit(pipex, "Error: Unable to create pipe", EXEC_ERROR);
	pid1 = fork();
	if (pid1 == -1)
		ft_exit(pipex, "Error: Unable to fork process for cmd1", EXEC_ERROR);
	else if (pid1 == 0)
		handle_child1(pipex, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_exit(pipex, "Error: Unable to fork process for cmd2", EXEC_ERROR);
	else if (pid2 == 0)
		handle_child2(pipex, pipe_fd);
	handle_parent(pipex, pipe_fd, pid1, pid2);
}
