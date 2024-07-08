/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:27:44 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/12 10:34:42 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = num * size;
	ptr = malloc(total_size);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, total_size);
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr = (int*)ft_calloc(5, sizeof(int));
    
    if (arr != NULL) {
        int i = 0;
        for (i < 5) {
            printf("%d ", arr[i]);
            i++;
        }
        printf("\n");
        free(arr);
    }
    return 0;
}
*/
