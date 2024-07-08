#include "pipex.h"

void ft_split_cmd()
{
    int i;
    i = 0;
    while(pipex.cmd[i])
    {
        pipex.cmd[i] = ft_split(pipex.cmd[i], ' ');
        i++;
    }
    return ;
}