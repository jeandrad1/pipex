/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:59:27 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 15:17:06 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parse(int argc, char **argv, t_args pipex)
{
	int	i;

	i = 0;
	if (argc != 5)
		exit_error(ARG_ERROR, 1, &pipex);
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
	pipex.cmd = malloc(sizeof(char *) * 3);
	if (!pipex.cmd)
		exit_error(CMD_ERROR, 1, &pipex);
	pipex.cmd[0] = argv[2];
	pipex.cmd[1] = argv[3];
	pipex.cmd[2] = NULL;
	if (access(pipex.infile, R_OK) == -1)
		exit_error(INFILE_ERROR, 1, &pipex);
	if (access(pipex.outfile, W_OK) == -1)
		exit_error(OUTFILE_ERROR, 1, &pipex);
	if (pipe(pipex.pipe_fd) == -1)
		exit_error(PIPE_ERROR, 1, &pipex);
	if ((pipex.infile_fd = open(pipex.infile, O_RDONLY)) == -1)
		exit_error(PIPEX_FILE_ERROR,1, &pipex);
	if ((pipex.outfile_fd = open(pipex.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		exit_error(PIPEX_FILE_ERROR, 1);
	return ;
}
