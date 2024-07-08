/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:56:07 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/12 10:24:00 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *s, const char *ne, size_t len)
{
	size_t	lit_len;
	size_t	hays_len;
	size_t	size;

	if (*ne == '\0')
		return ((char *)s);
	lit_len = ft_strlen(ne);
	hays_len = ft_strlen(s);
	if (hays_len < lit_len || len < lit_len)
		return (0);
	if (hays_len > len)
		size = len;
	else
		size = hays_len;
	while (size-- >= lit_len)
	{
		if (ft_memcmp(s, ne, lit_len) == 0)
			return ((char *)s);
		s++;
	}
	return (0);
}

/*
#include <stdio.h>

int main()
{
	const char *haystack = "Hello, world!";
	const char *ne = "world";
	
	char *result = ft_strnstr(haystack, ne, 13);
	
	if (result != 0)
	{
		printf("Substring found at index: %ld\n", result - haystack);
	}
	else
	{
		printf("Substring not found\n");
	}
	
	return 0;
}
*/