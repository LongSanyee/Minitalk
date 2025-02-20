/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:30:35 by rammisse          #+#    #+#             */
/*   Updated: 2024/11/21 12:53:04 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printaddresshelp(void *ptr)
{
	int				i;
	unsigned long	address;
	char			*buffer;

	i = 0;
	address = (unsigned long)ptr;
	buffer = "0123456789abcdef";
	if (address >= 16)
		i += ft_printaddresshelp((void *)(address / 16));
	i += ft_putchar(buffer[address % 16]);
	return (i);
}

int	ft_printaddress(void *ptr)
{
	int	i;

	i = 0;
	i += write (1, "0x", 2);
	i += ft_printaddresshelp(ptr);
	return (i);
}
