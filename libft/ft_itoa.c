/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:39:03 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/22 10:39:03 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nsize(long i)
{
	int	count;

	count = 0;
	if (i < 0)
		count++;
	while (i >= 10)
	{
		i /= 10;
		count++;
	}
	return (++count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_nsize(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n < 0)
			str[--i] = ((n % 10) * -1) + '0';
		else if (n > 0)
			str[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/* 
#include <stdio.h>
#include <limits.h>
#include "libft.h"

int main(){
    //int num = INT_MIN;
	//while (num <= INT_MAX){
		
		char *str = ft_itoa(52);
    	// printf("Number: %d\tString: %s\t", num, str);
		// printf("S Size: %d\n", ft_strlen(str));

		//num+=1000000000;
//	}
    return 0;
}
 */
