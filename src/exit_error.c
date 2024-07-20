/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:12:58 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/20 12:39:20 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Function to display the error message
// It receives an integer value with the error code
static void	error_parsing(int error)
{
	if (error == ARG_ERROR)
		ft_printf("ERROR: Arguments error\n");
	else if (error == CMD_ERROR)
		ft_printf("ERROR: Malloc for Command error\n");
	else if (error == INFILE_ERROR)
		ft_printf("ERROR: Infile error\n");
	else if (error == OUTFILE_ERROR)
		ft_printf("ERROR: Outfile error\n");
	else if (error == PIPE_ERROR)
		ft_printf("ERROR: Pipe error\n");
	else if (error == PIPEX_FILE_ERROR)
		ft_printf("ERROR: Pipex file error\n");
	else if (error == FORK_ERROR)
		ft_printf("ERROR: Fork error\n");
	else if (error == DUP2_ERROR)
		ft_printf("ERROR: Dup2 error\n");
	else
		ft_printf("ERROR: Unknown error\n");
}

// Function to display the error message and exit the program
// After displaying the help information
int	exit_error(int error, int is_exit, t_args *pipex, int is_free)
{
	error_parsing(error);
	if(is_free)
		ft_free_pipex(*pipex);
	if (is_exit)
		exit(error != NOTHING);
	return (error != NOTHING);
}