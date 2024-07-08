/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:47:04 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:24:02 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	numsign;
	int	i;
	int	num;

	i = 0;
	numsign = 1;
	num = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		numsign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) > 0)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * numsign);
}
/*
#include <stdio.h>
int main(){
	printf("%d", ft_atoi(" -1234ab567"));
	return (0);
}
*/