/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:30:57 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/12 09:51:09 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void	*dest, void const *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		*(dest_ptr + i) = *(src_ptr + i);
		i++;
	}
	return (dest_ptr);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
	char src[] = "Hello, world!";
	char dest[20];
	ft_memcpy(dest, src, strlen(src) + 1);
	printf("Copied string: %s\n", dest);
	return 0;
}
*/
