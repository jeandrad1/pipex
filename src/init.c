/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:57:51 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 09:28:45 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void ft_init_pipex(t_args *pipex)
{
    // Initialize pipex structure
    pipex->cmd1 = NULL;
    pipex->cmd2 = NULL;
    pipex->infile = NULL;
    pipex->outfile = NULL;
}
