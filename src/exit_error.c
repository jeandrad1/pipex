/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:12:58 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/26 11:11:08 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Function to display the error message and exit the program
// After displaying the help information
void	ft_exit(t_args *pipex, const char *error_message, int exit_code)
{
	ft_free_pipex(pipex);
	if (error_message)
		perror(error_message);
	exit(exit_code);
}
