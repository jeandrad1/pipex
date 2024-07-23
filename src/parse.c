/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:59:27 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/20 13:00:48 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_parse(int argc, char **argv, t_args pipex)
{
	if (argc != 5)
		exit_error(ARG_ERROR, 1, &pipex, 0);
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
	pipex.cmd1 = argv[2];
	pipex.cmd2 = argv[3];
	if (!pipex.cmd1 || !pipex.cmd2)
		exit_error(CMD_ERROR, 1, &pipex, 1);
	if (access(pipex.infile, R_OK) == -1)
		exit_error(INFILE_ERROR, 1, &pipex, 1);
	if (access(pipex.outfile, W_OK) == -1)
		exit_error(OUTFILE_ERROR, 1, &pipex, 0);
	if (pipe(pipex.pipe_fd) == -1)
		exit_error(PIPE_ERROR, 1, &pipex, 0);
	if ((pipex.infile_fd = open(pipex.infile, O_RDONLY)) == -1)
		exit_error(PIPEX_FILE_ERROR,1, &pipex, 0);
	if ((pipex.outfile_fd = open(pipex.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		exit_error(PIPEX_FILE_ERROR, 1, &pipex, 0);
	return ;
}
