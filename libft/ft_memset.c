/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:51:55 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 11:32:18 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *) str;
	while (n > 0)
	{
		*s = (unsigned char) c;
		s++;
		n--;
	}
	return (str);
}
