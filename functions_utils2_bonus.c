/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:03:37 by ansebast          #+#    #+#             */
/*   Updated: 2024/11/21 23:36:01 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isempty(char *str)
{
	return (*str == '\0');
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_puterror(char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s != '\0')
		write(fd, s++, 1);
}
