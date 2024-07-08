/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:24 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 15:15:39 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipex(t_args pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd[i])
	{
		free(pipex->cmd[i]);
		i++;
	}
	free(pipex->cmd);
	free(pipex->infile);
	free(pipex->outfile);
	free(pipex);
}
