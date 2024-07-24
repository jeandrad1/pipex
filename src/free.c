/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:24 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 09:24:46 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void ft_free_pipex(t_args *pipex) {
    if (pipex->cmd1) {
        for (int i = 0; pipex->cmd1[i] != NULL; i++) {
            free(pipex->cmd1[i]);
        }
        free(pipex->cmd1);
    }

    if (pipex->cmd2) {
        for (int i = 0; pipex->cmd2[i] != NULL; i++) {
            free(pipex->cmd2[i]);
        }
        free(pipex->cmd2);
    }
}

