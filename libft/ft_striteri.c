/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:53:44 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/17 11:53:44 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>  

int main(){
    char s []= "abcde98765fghijklm123abc";
    int i = 0;
    while (i < ft_strlen(s))
    {
        printf(ft_striteri(s,    ));
        i++;
    }
    return (0);
}
*/