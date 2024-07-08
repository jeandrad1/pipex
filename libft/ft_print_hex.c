/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:33:29 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:24:48 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int n)
{
	char	*hex;
	int		i;
	int		count;

	hex = "0123456789abcdef";
	i = 0;
	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16);
	ft_putchar(hex[n % 16]);
	count++;
	return (count);
}
