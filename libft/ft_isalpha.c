/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:23:51 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:24:14 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	if (c <= 'Z' && c >= 'A')
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int i = 0;
	while (i < 253){
		printf("ft_isalpha: %i\t", ft_isalpha(i));
		printf("isalpha: %i\n", isalpha(i));
		i++;
	}
	return (0);
}
*/