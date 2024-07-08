/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:20:32 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/12 10:20:34 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int		r;
	size_t	i;

	r = 0;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
		{
			r = (unsigned char) str1[i] - (unsigned char) str2[i];
			return (r);
		}
		i++;
	}
	return (r);
}
/*
#include <stdio.h>
#include <string.h>
int main(void) {
	const char *str1 = "Hello ";
	const char *str2 = "Hello";
	int n = 6;
	int result = ft_strncmp(str1, str2, n);
	
	printf("Result: %d\n", result);
	printf("Result: %d\n", strncmp(str1,str2,n));

	return (0);
}
*/