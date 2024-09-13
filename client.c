/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:32 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/13 01:33:00 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		g_signal_received;

void	wait_signal(int signal)
{
        if (signal == 10)
	        g_signal_received = 1;
        if (signal == 12)
                ft_puterror("There is another process sending message. Wait 1 second!", 2);
}

static void	send_signal(long pid, unsigned char bit)
{
	if (bit == '0')
		kill(pid, SIGUSR1);
	else if (bit == '1')
		kill(pid, SIGUSR2);
	while (g_signal_received == 0)
		;
	g_signal_received = 0;
}

void	send_bits(int count, int ch, long pid, void (f)(long pid,
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
	long	pid;
	int		i;
	int		j;

	validate_client_args(ac, av);
	pid = ft_atol(av[1]);
	i = 0;
	j = 8;
	signal(SIGUSR1, wait_signal);
        signal(SIGUSR2, wait_signal);
	while (av[2][i] != '\0')
	{
		send_bits(j, av[2][i], pid, send_signal);
		j = 8;
		i++;
	}
        send_bits(j, '\n', pid, send_signal);
	send_bits(j, av[2][i], pid, send_signal);
	exit(0);
	return (0);
}
