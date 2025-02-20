/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexalower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:05:08 by rammisse          #+#    #+#             */
/*   Updated: 2024/11/21 12:53:19 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexalower(unsigned int n)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = "0123456789abcdef";
	if (n >= 16)
		i += ft_printhexalower(n / 16);
	i += ft_putchar(buffer[n % 16]);
	return (i);
}
