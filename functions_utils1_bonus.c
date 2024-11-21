/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:54:33 by ansebast          #+#    #+#             */
/*   Updated: 2024/11/21 23:19:00 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

long	ft_atol(const char *str)
{
	int		i;
	int		signal;
	long	num;

	signal = 1;
	num = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * signal);
}

long int	ft_strtol(char *str, char **endptr)
{
	int		i;
	int		signal;
	long	num;

	signal = 1;
	num = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	*endptr = &str[i];
	return (num * signal);
}

void	ft_putnbr_fd(long n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10 + '0'), fd);
}

int	ft_isint(char *str)
{
	char	*endptr;

	if (*str == '\0' || (*str == '-' && *(str + 1) == '\0') || (*str == '+'
			&& *(str + 1) == '\0'))
		return (0);
	ft_strtol(str, &endptr);
	if (*endptr != '\0')
		return (0);
	return (1);
}

int	ft_isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}
