/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:59:27 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 09:44:52 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void check_and_set_env() {
    if (getenv("PATH") == NULL) {
        setenv("PATH", "/usr/bin:/bin", 1);
    }
    // Add checks for other essential environment variables if needed
}

char **split_command(const char *command) {
    char **args = NULL;
    char *cmd_copy = ft_strdup(command);
    char *token = ft_strtok(cmd_copy, " ");
    int count = 0;

    while (token)
	{
        args = realloc(args, sizeof(char *) * (count + 1));
        args[count] = ft_strdup(token);
        count++;
        token = ft_strtok(NULL, " ");
    }
    args = realloc(args, sizeof(char *) * (count + 1));
    args[count] = NULL;

    free(cmd_copy);
    return args;
}

void ft_parse(int argc, char **argv, t_args *pipex)
{
    if (argc != 5) {
        ft_exit(pipex, "Usage: ./pipex infile command1 command2 outfile", EXIT_FAILURE);
    }
    pipex->infile = argv[1];
    pipex->cmd1 = split_command(argv[2]);
    pipex->cmd2 = split_command(argv[3]);
    pipex->outfile = argv[4];

    // Check if infile is valid
    int infile_fd = open(pipex->infile, O_RDONLY);
    if (infile_fd == -1) {
        ft_exit(pipex, "Error: Unable to open infile", EXIT_FAILURE);
    }
    close(infile_fd);

    // Check and set essential environment variables
    check_and_set_env();
}
