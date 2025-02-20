/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:44:28 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/20 20:39:39 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

void	extractbits(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		id;
	int		i;
	char	*str;

	if (ac != 3)
	{
		ft_printf("USAGE: ./client <PID> <MESSAGE>\n");
		return (0);
	}
	id = ft_atoi(av[1]);
	i = 0;
	str = av[2];
	while (str[i])
		extractbits(id, str[i++]);
	extractbits(id, '\0');
	extractbits(id, '\n');
}
