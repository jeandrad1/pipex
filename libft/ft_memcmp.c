/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:28:46 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/12 09:49:05 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *) str1;
	p2 = (const unsigned char *) str2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Hello ";
	char str2[] = "Hello";
	size_t n = 6;
	int result1 = ft_memcmp(str1, str2, n);
	int result2 = memcmp(str1, str2, n);
	printf("ft_memcmp: %d\n", result1);
	printf("memcmp: %d\n", result2);
	return (0);
}
*/
