/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:48:17 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/17 12:02:36 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	len;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	res = (char *) malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}
/*
#include <stdio.h>

int main() {
    char const *s1 = "abcde98765fghijklm123abc";
    char const *set = "abc";
    char *p_trim;
    p_trim = ft_strtrim(s1, set);
    printf("test: %s\n", p_trim);
    return 0;
}
*/