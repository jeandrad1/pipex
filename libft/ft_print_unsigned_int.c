/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:36:43 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:25:02 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_int(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned_int(n / 10);
	ft_putchar(n % 10 + '0');
	count++;
	return (count);
}
