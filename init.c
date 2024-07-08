#include "pipex.h"

void ft_init_pipex(int argc, char **argv)
{
    struct s_pipex pipex;

    pipex.cmd = NULL;
    pipex.infile = NULL;
    pipex.outfile = NULL;
    pipex.infile_fd = -1;
    pipex.outfile_fd = -1;
    pipex.pipe_fd[0] = -1;
    pipex.pipe_fd[1] = -1;
    pipex.pid = -1;
    return (pipex);
}