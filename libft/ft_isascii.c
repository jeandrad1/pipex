/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:53:37 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:24:17 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	while(i <254)
	{
		printf("ft_isascii: %i\t", ft_isascii(i));
		printf("isascii: %i\n", isascii(i));
		i++;
	}
	return (0);
}
*/
