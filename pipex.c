#include "pipex.h"
int main (int argc, char **argv)
{
    ft_init_pipex(argc, argv);
    ft_parse(argc, argv);
    ft_split_cmd();
    ft_exec_cmd();
    
    return(EXIT_SUCCESS);
}