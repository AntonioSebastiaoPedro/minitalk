/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:44 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/05 16:55:48 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	hand_siguser(int sig)
{
	(void)sig;
	// if (sig == SIGUSR1)
	printf("Sig 1\n");
	// else if (sig == SIGUSR2)
	printf("Sig 2\n");
}

int	main(void)
{
	int pid;

	pid = getpid();
	printf("PID: %d \n", pid);

	while (1)
	{
		if (signal(SIGUSR1, hand_siguser) == SIG_ERR)
		{
			fprintf(stderr, "can't catch SIGUSR1\n");
			exit(1);
		}
		if (signal(SIGUSR2, hand_siguser) == SIG_ERR)
		{
			fprintf(stderr, "can't catch SIGUSR2\n");
			exit(1);
		}
	}
	return (0);
}