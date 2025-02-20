/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:42:53 by rammisse          #+#    #+#             */
/*   Updated: 2024/11/21 13:55:47 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	char	buffr[11];
	int		p;
	int		i;

	i = 0;
	p = 0;
	if (n == 0)
		p += write (1, "0", 1);
	while (n > 0)
	{
		buffr[i++] = (n % 10) + '0';
		n = n / 10;
	}
	i--;
	while (i >= 0)
	{
		p += write (1, &buffr[i--], 1);
	}
	return (p);
}
