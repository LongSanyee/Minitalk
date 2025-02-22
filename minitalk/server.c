/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:47:10 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/22 18:40:57 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signalget(int sig, siginfo_t *info, void *content)
{
	static int	bit = 0;
	static int	id = 0;
	static char	character = 0;

	(void)content;
	if (id != info->si_pid)
	{
		bit = 0;
		character = 0;
		id = info->si_pid;
	}
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
	sa.sa_sigaction = signalget;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	ft_putnbr(getpid());
	while (1)
		pause();
}
