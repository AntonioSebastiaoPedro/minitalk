/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:32 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/05 13:21:17 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int     pid;
        int     status;
        // int     bit;
        int     i;
        int     j;

        if (ac != 3)
        {
                printf("Usage: ./client <pid server> <string to send>");
                exit(1);
        }
	pid = atoi(av[1]);
	printf("PID SERVER: %d \n", pid);
        status = kill(pid, 23);
        if (!status)
        {
                printf("Success\n");
                i = 0;
                j = 8;
                while (av[2][i])
                {
                        while (j--)
                        {
                                printf("%c", ((av[2][i] >> j & 1) + '0'));
                        }
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