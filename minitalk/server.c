/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:47:10 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/20 20:35:24 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

void	signalget(int sig)
{
	static int	bit = 0;
	static char	character = 0;

	if (sig == SIGUSR2)
		character |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write (1, &character, 1);
		bit = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		return (0);
	sa.sa_handler = signalget;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
}
