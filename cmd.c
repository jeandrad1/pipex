/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:18:59 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 12:55:12 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_split_cmd()
{
	int	i;

	i = 0;
	while(pipex.cmd[i])
	{
		t_args.cmd[i] = ft_split(pipex.cmd[i], ' ');
		i++;
	}
	return ;
}
