/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:06:40 by rammisse          #+#    #+#             */
/*   Updated: 2024/11/21 16:10:29 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_buff(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		count += ft_printhexalower(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_printhexaupper(va_arg(args, unsigned int));
	else if (c == 'u')
		count += ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_printaddress(va_arg(args, void *));
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		j;
	size_t	i;

	va_start(args, str);
	j = 0;
	i = 0;
	if (write (1, 0, 0) == -1)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			j += ft_print_buff(str[i], args);
		}
		else
			j += ft_putchar(str[i]);
		i++;
	}
	return (j);
}
