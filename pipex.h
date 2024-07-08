#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

struct s_pipex
{
    char **cmd;
    char *infile;
    char *outfile;
    int infile_fd;
    int outfile_fd;
    int pipe_fd[2];
    int pid;
};

void ft_init_pipex(int argc, char **argv);
void ft_parse(int argc, char **argv);