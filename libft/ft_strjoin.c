/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:22:55 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:25:27 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_strcat(char *dst, const char *src)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) +ft_strlen(s2);
	str = (char *)malloc (sizeof(*str) *(len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1)+1);
	ft_strcat(str, s2);
	return (str);
}

/*
#include <stdio.h>
#include "libft.h"

int main(void){
    char s1 [] = "Hello,";
    char s2 [] = " world!";
    char *result = ft_strjoin(s1, s2);
    printf("%s\n", result);
    return 0;
}
*/