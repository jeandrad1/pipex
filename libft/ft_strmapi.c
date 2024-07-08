/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:16:59 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/17 10:16:59 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

int main(){
    char const *s = "abcde98765fghijklm123abc";
    char *p_trim;
    p_trim = ft_strmapi(s, ft_toupper);
    printf("test: %s\n", p_trim);
    return 0;
}
*/