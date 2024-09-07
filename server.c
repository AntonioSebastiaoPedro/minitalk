/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:44 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/07 09:11:57 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	client_pid;

void    hand_quit(int signal)
{
        (void)signal;
        ft_putstr_fd("\n\nYou shut down the server\n", 1);
        exit(0);
}

void	hand_siguser(int sig, siginfo_t *info, void *context)
{
	static char	value;
	static int	count;

	if (client_pid <= 0)
		client_pid = info->si_pid;
	if (client_pid == info->si_pid)
	{
		(void)context;
		value = value << 1;
		if (sig == SIGUSR2)
			value++;
		++count;
		if (count == 8)
		{
			write(1, &value, 1);
			count = 0;
			if (value == '\0')
			{
				kill(client_pid, SIGUSR1);
				client_pid = -123;
			}
			value = 0;
		}
		kill(client_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction action;
	long pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	action.sa_sigaction = hand_siguser;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
        signal(SIGINT, hand_quit);

	while (1)
		pause();
	return (0);
}