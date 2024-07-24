/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:34:06 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 11:54:07 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strspn(const char *s, const char *accept)
{
	const char	*p;
	const char	*a;
	size_t		count;

	p = s;
	count = 0;
	while (*p != '\0')
	{
		a = accept;
		while (*a != '\0')
		{
			if (*p == *a)
				break ;
			++a;
		}
		if (*a == '\0')
			return (count);
		count++;
		p++;
	}
	return (count);
}

static size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*p;
	const char	*r;
	size_t		count;

	p = s;
	count = 0;
	while (*p != '\0')
	{
		r = reject;
		while (*r != '\0')
		{
			if (*p == *r)
			{
				return (count);
			}
			++r;
		}
		++count;
		++p;
	}
	return (count);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last;
	char		*end;

	if (str == NULL)
		str = last;
	if (str == NULL)
		return (NULL);
	str += ft_strspn(str, delim);
	if (*str == '\0')
		return (NULL);
	end = str + ft_strcspn(str, delim);
	if (*end == '\0')
		last = (NULL);
	else
	{
		*end = '\0';
		last = end + 1;
	}
	return (str);
}
