/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:12:58 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 13:25:57 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// Function to display the error message
// It receives an integer value with the error code
static void	error_parsing(int error)
{
	if (error == ARG_ERROR)
		perror("ERROR: Arguments error\n");
	else if (error == CMD_ERROR)
		perror("ERROR: Malloc for Command error\n");
	else if (error == INFILE_ERROR)
		perror("ERROR: Infile error\n");
	else if (error == OUTFILE_ERROR)
		perror("ERROR: Outfile error\n");
	else if (error == PIPE_ERROR)
		perror("ERROR: Pipe error\n");
	else if (error == PIPEX_FILE_ERROR)
		perror("ERROR: Pipex file error\n");
	else
		perror("ERROR: Unknown error\n");
}

// Function to display the error message and exit the program
// After displaying the help information
int	exit_error(int error, int is_exit)
{
	error_parsing(error);
	if (is_exit)
		exit(error != NOTHING);
	return (error != NOTHING);
}