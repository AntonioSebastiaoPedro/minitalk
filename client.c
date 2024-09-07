/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:32 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/07 07:20:23 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		signal_received;

void	wait_signal(int signal)
{
	(void)signal;
	signal_received = 1;
}

void	send_signal(long pid, unsigned char bit)
{
	if (bit == '0')
		kill(pid, SIGUSR1);
	else if (bit == '1')
		kill(pid, SIGUSR2);
	while (signal_received == 0)
		;
	signal_received = 0;
}

void	send_bits(int count, int ch, long pid, void(f)(long pid,
			unsigned char bit))
{
	unsigned char	bit;

	while (count--)
	{
		bit = ((ch >> count & 1) + '0');
		f(pid, bit);
	}
}

int	main(int ac, char **av)
{
	long pid;
	int i;
	int j;

	validate_arguments(ac, av);
	pid = ft_atol(av[1]);
	i = 0;
	j = 8;
	signal(SIGUSR1, wait_signal);
	while (av[2][i] != '\0')
	{
		send_bits(j, av[2][i], pid, send_signal);
		j = 8;
		i++;
	}
	send_bits(j, av[2][i], pid, send_signal);
	exit(0);
	return (0);
}