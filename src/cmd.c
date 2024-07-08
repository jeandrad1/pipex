/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:18:59 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/08 15:45:42 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_split_cmd(t_args pipex)
{
	char	**tmp;
	int		i;

	i = 0;
	if (!pipex.cmd)
		exit_error(CMD_ERROR, 1, &pipex);
	tmp = ft_split(pipex.cmd[0], ' ');
	if (!tmp)
		exit_error(CMD_ERROR, 1, &pipex);
	pipex.cmd[0] = ft_strdup(tmp[0]);
	pipex.cmd[1] = ft_strdup(tmp[1]);
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return ;
}
