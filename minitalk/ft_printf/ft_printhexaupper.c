/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:38:06 by rammisse          #+#    #+#             */
/*   Updated: 2024/11/21 12:53:21 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexaupper(unsigned int n)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_printhexaupper(n / 16);
	i += ft_putchar(buffer[n % 16]);
	return (i);
}
