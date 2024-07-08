/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:40:35 by jeandrad          #+#    #+#             */
/*   Updated: 2023/12/12 11:38:57 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *) dest;
	s = (char *) src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}

/*
int main() {
    char str1[] = "Hello, World!";
    char str2[20];

    ft_memmove(str2, str1, sizeof(str1));

    printf("str2: %s\n", str2);

    return 0;
}
*/