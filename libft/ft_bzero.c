/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:43:54 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:24:05 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
#include "libft.h"

int main() {
	char s[] = "Esto todo ahi que borrarlo.";
	printf("%s\n", s);
	ft_bzero(s, 5);
	printf("%s\n", s);
	return 0;
}
*/

/*
#include<stdio.h>
int main(){
	char s [] = "Esto todo ahi que borrarlo.";
	printf("%s\n",s);
	ft_bzero(s,5);
	printf("%s\n",s);
	return (0);
}
*/
