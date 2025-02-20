/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:06:55 by rammisse          #+#    #+#             */
/*   Updated: 2024/11/21 13:53:25 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	i;
	int		p;

	p = 0;
	i = 0;
	if (!str)
		return ((write (1, "(null)", 6)));
	while (str[i])
	{
		p += write (1, &str[i], 1);
		i++;
	}
	return (p);
}
