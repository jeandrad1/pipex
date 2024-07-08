/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:04:36 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:25:06 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_arg(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (type == 'u')
		count += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (type == 'x')
		count += ft_print_hex(va_arg(args, unsigned int));
	else if (type == 'X')
		count += ft_print_hex_mayus(va_arg(args, unsigned int));
	else if (type == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(type);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_print_arg(str[i + 1], args);
			i = i + 2;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int main() {
	int count1, count2;

	count1 = ft_printf("Testing printf: %s, %c\n", "Hello", 'A');
	count2 = printf("Testing printf: %s, %c\n", "Hello", 'A');

	printf("ft_printf count: %d\n", count1);
	printf("printf count: %d\n", count2);

	return 0;
}
*/