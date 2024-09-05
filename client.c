/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:32 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/05 18:52:55 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void    send_signal(int pid, unsigned char bit)
{       

        if (bit == '0')
        {
                kill(pid, SIGUSR1);
        }
        else if (bit == '1')
        {
                kill(pid, SIGUSR2);
        }
}

int	main(int ac, char **av)
{
	int     pid;
        int     status;
        int     i;
        int     j;
        unsigned char     bit;

        if (ac != 3)
        {
                printf("Usage: ./client <pid server> <string to send>");
                exit(1);
        }
	pid = atoi(av[1]);
        status = kill(pid, 23);
        if (!status)
        {
                printf("Success\n");
                i = 0;
                j = 8;
                while (av[2][i] != '\0')
                {
                        while (j--)
                        {
                                bit = ((av[2][i] >> j & 1) + '0');
                                send_signal(pid, bit);
                                usleep(350);
                        }
                        j = 8;
                        bit = 0;
                        i++;
                }
                exit(0);
        }
        else
        {
                printf("Error");
                exit(1);
        }
	return (0);
}