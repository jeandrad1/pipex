/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:06:02 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:24:22 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(){
	int i = 0;
	while (i <253)
	{
		printf("ft_isdigit: %i\t",ft_isdigit(i));
		printf("isdigit: %i\n", isdigit(i));
		i++;
	}
	return (0);
}
*/