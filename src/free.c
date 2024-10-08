/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:24 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 14:45:03 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Free the pipex structure
// It frees each element of the cmd1 and cmd2 arrays
// And then frees the arrays
void	ft_free_pipex(t_args *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd1)
	{
		while (pipex->cmd1[i] != NULL)
		{
			free(pipex->cmd1[i]);
			i++;
		}
		free(pipex->cmd1);
	}
	i = 0;
	if (pipex->cmd2)
	{
		while (pipex->cmd2[i] != NULL)
		{
			free(pipex->cmd2[i]);
			i++;
		}
		free(pipex->cmd2);
	}
}
