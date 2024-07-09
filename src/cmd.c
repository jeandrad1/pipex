/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:18:59 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/09 17:38:48 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_split_cmd(t_args pipex)
{
	int i;
	char **split_res1;
	char **split_res2;

	printf("cmd1: %s\n", pipex.cmd1);
	i = 0;
	split_res1 = ft_split(pipex.cmd1, ' ');
	split_res2 = ft_split(pipex.cmd2, ' ');

	printf("cmd1: %s\n", split_res1[0]);

	pipex.cmd[0] = split_res1[0];
	pipex.cmd[1] = split_res2[0];

	printf("cmd1: %s\n", pipex.cmd[0]);
	
	return ;
}
