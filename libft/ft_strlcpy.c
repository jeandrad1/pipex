/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:33:17 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:25:30 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i])
	{
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
int main(){
	printf("ft_strlcpy: %d\n", ft_strlcpy("Sobreescribe", "copia", 3));
	printf("strlcpy: %d\n",ft_strlcpy("Sobreescribe","copia",3));
	return (0);
}
*/