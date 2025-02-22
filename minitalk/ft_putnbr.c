/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:33:19 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/22 18:40:13 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	negative(int *n)
{
	if (*n < 0)
	{
		write (1, "-", 1);
		*n *= -1;
	}
}

void	ft_putnbr(int n)
{
	char	buffr[12];
	int		i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 12);
		return ;
	}
	negative(&n);
	while (n > 0)
	{
		buffr[i++] = (n % 10) + '0';
		n = n / 10;
	}
	i--;
	while (i >= 0)
	{
		write (1, &buffr[i--], 1);
	}
}
