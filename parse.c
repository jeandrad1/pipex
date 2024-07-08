#include "pipex.h"

void parse(int argc, char **argv)
{
    int i;

    i = 0;
    if(argc != 5)
        exit_error(1,1);
    pipex.infile = argv[1];
    pipex.outfile = argv[4];
    pipex.cmd = malloc(sizeof(char *) * 3);
    if(!pipex.cmd)
        exit_error(1,1);
    pipex.cmd[0] = argv[2];
    pipex.cmd[1] = argv[3];
    pipex.cmd[2] = NULL;
    if(access(pipex.infile, R_OK) == -1)
        exit_error(1,1);
    if(access(pipex.outfile, W_OK) == -1)
        exit_error(1,1);
    if(pipe(pipex.pipe_fd) == -1)
        exit_error(1,1);
    if((pipex.infile_fd = open(pipex.infile, O_RDONLY)) == -1)
        exit_error(1,1);
    if((pipex.outfile_fd = open(pipex.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
        exit_error(1,1);
    return ;
}