/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:44 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/05 18:51:27 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	hand_siguser(int sig)
{
        static int     value;
        static int     count;
        
        value *= 2;
	if (sig == SIGUSR2)
                value += 1;
        ++count;
	if (count == 8)
        {
                write(1, &value, 1);
                count = 0;
                value = 0;
        }        
}

int	main(void)
{
	int pid;

	pid = getpid();
	printf("PID: %d \n", pid);

        signal(SIGUSR1, hand_siguser);
        signal(SIGUSR2, hand_siguser);
        
	while (1)
	{
                pause();
	}
	return (0);
}