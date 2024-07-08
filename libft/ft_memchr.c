/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:54:45 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/16 10:28:43 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	i = 0;
	str = (const unsigned char *) s;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	const char *str = "Hello, World!";
	int search_char = 'o';
	size_t search_len = strlen(str);

	void *result = ft_memchr(str, search_char, search_len);

	if (result != NULL) {
		printf("Character '%c' found at index %ld\n",
	   	search_char, (char *)result - str);
	} else {
		printf("Character '%c' not found\n", search_char);
	}

	return 0;
}
*/
