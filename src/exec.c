/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:07:10 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 09:29:30 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void ft_exec_cmd(t_args *pipex) {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        ft_exit(pipex, "Error: Unable to create pipe", EXIT_FAILURE);
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        ft_exit(pipex, "Error: Unable to fork process for cmd1", EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Child process for command1
        int infile_fd = open(pipex->infile, O_RDONLY);
        if (infile_fd == -1) {
            ft_exit(pipex, "Error: Unable to open infile in child process", EXIT_FAILURE);
        }
        dup2(infile_fd, STDIN_FILENO);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(infile_fd); // Close infile_fd after duplicating
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execvp(pipex->cmd1[0], pipex->cmd1);
        ft_exit(pipex, "Error: execvp failed for cmd1", EXIT_FAILURE);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        ft_exit(pipex, "Error: Unable to fork process for cmd2", EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Child process for command2
        int outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile_fd == -1) {
            ft_exit(pipex, "Error: Unable to open outfile in child process", EXIT_FAILURE);
        }
        dup2(pipe_fd[0], STDIN_FILENO);
        dup2(outfile_fd, STDOUT_FILENO);
        close(outfile_fd); // Close outfile_fd after duplicating
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execvp(pipex->cmd2[0], pipex->cmd2);
        ft_exit(pipex, "Error: execvp failed for cmd2", EXIT_FAILURE);
    }

    // Parent process
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    int status1, status2;
    if (waitpid(pid1, &status1, 0) == -1) {
        ft_exit(pipex, "Error: waitpid failed for cmd1", EXIT_FAILURE);
    }
    if (waitpid(pid2, &status2, 0) == -1) {
        ft_exit(pipex, "Error: waitpid failed for cmd2", EXIT_FAILURE);
    }

    if (status1 != 0) {
        ft_exit(pipex, "Error: cmd1 failed", status1);
    }

    if (status2 != 0) {
        ft_exit(pipex, "Error: cmd2 failed", status2);
    }
}
