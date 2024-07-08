#include "pipex.h"

void ft_exec_cmd()
{
    s_pipex.pid = fork();
    if (s_pipex.pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (s_pipex.pid == 0)
    {
        if (s_pipex.infile_fd != -1)
        {
            if (dup2(s_pipex.infile_fd, STDIN_FILENO) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
        }
        if (s_pipex.outfile_fd != -1)
        {
            if (dup2(s_pipex.outfile_fd, STDOUT_FILENO) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
        }
        if (s_pipex.pipe_fd[1] != -1)
        {
            if (dup2(s_pipex.pipe_fd[1], STDOUT_FILENO) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
        }
        if (s_pipex.pipe_fd[0] != -1)
        {
            if (dup2(s_pipex.pipe_fd[0], STDIN_FILENO) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
        }
        execve(s_pipex.cmd[0], s_pipex.cmd, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(s_pipex.pid, NULL, 0);
    }
}