/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:35:03 by rammisse          #+#    #+#             */
/*   Updated: 2024/11/21 13:57:38 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	returnezero(int p)
{
	p += write (1, "0", 1);
	return (p);
}

static int	inmin(int p)
{
	p += write (1, "-2147483648", 11);
	return (p);
}

static int	negative(int *n, int p)
{
	if (*n < 0)
	{
		p += write (1, "-", 1);
		*n *= -1;
	}
	return (p);
}

int	ft_putnbr(int n)
{
	char	buffr[12];
	int		p;
	int		i;

	p = 0;
	i = 0;
	if (n == 0)
		return (returnezero(p));
	if (n == -2147483648)
		return (inmin(p));
	p = negative(&n, p);
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
