/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:21:27 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:24:11 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (1);
	if (ft_isalpha(c))
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
	while(i < 250)
	{
		printf("ft_isalnum: %i\t", ft_isalnum(i));
		printf("isalnum: %i\n", isalnum(i));
		i++;
	}
	return (0);
}
*/