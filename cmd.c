/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:18:59 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 13:06:49 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_split_cmd(t_args pipex)
{
	int	i;

	i = 0;
	while (pipex.cmd[i])
	{
		pipex.cmd[i] = ft_split(pipex.cmd[i], ' ');
		i++;
	}
	return ;
}
