/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:27:17 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/09 12:29:28 by jeandrad         ###   ########.fr       */
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

void	error_parsing(int error)
{
	if (error == ARG_ERROR)
		ft_printf("ERROR: Arguments error\n");
	else if (error == CMD_ERROR)
		ft_printf("ERROR: Malloc for Command error\n");
	else if (error == INFILE_ERROR)
		ft_printf("ERROR: Infile error\n");
	else if (error == OUTFILE_ERROR)
		ft_printf("ERROR: Outfile error\n");
	else if (error == PIPE_ERROR)
		ft_printf("ERROR: Pipe error\n");
	else if (error == PIPEX_FILE_ERROR)
		ft_printf("ERROR: Pipex file error\n");
	else if (error == FORK_ERROR)
		ft_printf("ERROR: Fork error\n");
	else if (error == DUP2_ERROR)
		ft_printf("ERROR: Dup2 error\n");
	else
		ft_printf("ERROR: Unknown error\n");
}

// Function to display the error message and exit the program
// After displaying the help information
int	exit_error(int error, int is_exit, t_args *pipex)
{
	error_parsing(error);
	ft_free_pipex(*pipex);
	if (is_exit)
		exit(error != NOTHING);
	return (error != NOTHING);
}
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

void	error_parsing(int error)
{
	if (error == ARG_ERROR)
		ft_printf("ERROR: Arguments error\n");
	else if (error == CMD_ERROR)
		ft_printf("ERROR: Malloc for Command error\n");
	else if (error == INFILE_ERROR)
		ft_printf("ERROR: Infile error\n");
	else if (error == OUTFILE_ERROR)
		ft_printf("ERROR: Outfile error\n");
	else if (error == PIPE_ERROR)
		ft_printf("ERROR: Pipe error\n");
	else if (error == PIPEX_FILE_ERROR)
		ft_printf("ERROR: Pipex file error\n");
	else if (error == FORK_ERROR)
		ft_printf("ERROR: Fork error\n");
	else if (error == DUP2_ERROR)
		ft_printf("ERROR: Dup2 error\n");
}
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

void	error_parsing(int error)
{
	if (error == ARG_ERROR)
		ft_printf("ERROR: Arguments error\n");
	else if (error == CMD_ERROR)
		ft_printf("ERROR: Malloc for Command error\n");
	else if (error == INFILE_ERROR)
		ft_printf("ERROR: Infile error\n");
	else if (error == OUTFILE_ERROR)
		ft_printf("ERROR: Outfile error\n");
	else if (error == PIPE_ERROR)
		ft_printf("ERROR: Pipe error\n");
	else if (error == PIPEX_FILE_ERROR)
		ft_printf("ERROR: Pipex file error\n");
	else if (error == FORK_ERROR)
		ft_printf("ERROR: Fork error\n");
	else if (error == DUP2_ERROR)
		ft_printf("ERROR: Dup2 error\n")
	pipex.outfile = argv[4];
	pipex.cmd = malloc(sizeof(char *) * 2);
	if (!pipex.cmd)
		exit_error(CMD_ERROR, 1, &pipex);
	pipex.cmd[0] = argv[2];
	pipex.cmd[1] = argv[3];#include "../includes/pipex.h"

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

void	error_parsing(int error)
{
	if (error == ARG_ERROR)
		ft_printf("ERROR: Arguments error\n");
	else if (error == CMD_ERROR)
		ft_printf("ERROR: Malloc for Command error\n");
	else if (error == INFILE_ERROR)
		ft_printf("ERROR: Infile error\n");
	else if (error == OUTFILE_ERROR)
		ft_printf("ERROR: Outfile error\n");
	else if (error == PIPE_ERROR)
		ft_printf("ERROR: Pipe error\n");
	else if (error == PIPEX_FILE_ERROR)
		ft_printf("ERROR: Pipex file error\n");
	else if (error == FORK_ERROR)
		ft_printf("ERROR: Fork error\n");
	else if (error == DUP2_ERROR)
		ft_printf("ERROR: Dup2 error\n")
	if (access(pipex.infile, R_OK) == -1)
		exit_error(INFILE_ERROR, 1, &pipex);
	if (access(pipex.outfile, W_OK) == -1)
		exit_error(OUTFILE_ERROR, 1, &pipex);
	if (pipe(pipex.pipe_fd) == -1)
		exit_error(PIPE_ERROR, 1, &pipex);
	if ((pipex.infile_fd = open(pipex.infile, O_RDONLY)) == -1)
		exit_error(PIPEX_FILE_ERROR,1, &pipex);
	if ((pipex.outfile_fd = open(pipex.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		exit_error(PIPEX_FILE_ERROR, 1, &pipex);
	return ;
}

void	ft_split_cmd(t_args pipex)
{
	printf("%s\n",pipex.cmd[0]);
//	printf("%s\n",pipex.cmd[1]);
}

void	ft_exec_cmd(t_args pipex)
{
	pipex.pid = fork();
	if (pipex.pid == -1)
		exit_error(FORK_ERROR, 1, &pipex);
	if (pipex.pid == 0)
	{
		if (pipex.infile_fd != -1)
		{
			if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex);
		}
		if (pipex.outfile_fd != -1)
		{
			if (dup2(pipex.outfile_fd, STDOUT_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex);
		}
		if (pipex.pipe_fd[1] != -1)
		{
			if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex);
		}
		if (pipex.pipe_fd[0] != -1)
		{
			if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
				exit_error(DUP2_ERROR, 1, &pipex);
		}
		execve(pipex.cmd[0], pipex.cmd, NULL);
		exit_error(EXEC_ERROR, 1, &pipex);
	}
	else
		wait(NULL);
}

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
}

// Main function
int	main(int argc, char **argv)
{
	t_args	pipex;

// Initialize the structure in order to avoid garbage values
	ft_memset(&pipex, 0, sizeof(t_args));
	printf("memset OK\n");

// Initialize the structure
	ft_init_pipex(pipex);
	printf("init OK\n");

// Parse the arguments
	ft_parse(argc, argv, pipex);
	printf("parse OK\n");

// Split the command
	ft_split_cmd(pipex);
	printf("split OK\n");

// Execute the command
	ft_exec_cmd(pipex);
	printf("exec OK\n");

// Free the structure
	ft_free_pipex(pipex);
	printf("free OK\n");

// Return the program
	return (EXIT_SUCCESS);
}

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
}

// Main function
int	main(int argc, char **argv)
{
	t_args	pipex;void	ft_parse(int argc, char **argv, t_args pipex)


// Initialize the structure in order to avoid garbage values
	ft_memset(&pipex, 0, sizeof(t_args));
	printf("memset OK\n");

// Initialize the structure
	ft_init_pipex(pipex);
	printf("init OK\n");

// Parse the arguments
	ft_parse(argc, argv, pipex);
	printf("parse OK\n");

// Split the command
	ft_split_cmd(pipex);
	printf("split OK\n");

// Execute the command
	ft_exec_cmd(pipex);
	printf("exec OK\n");

// Free the structure
	ft_free_pipex(pipex);
	printf("free OK\n");

// Return the program
	return (EXIT_SUCCESS);
}
