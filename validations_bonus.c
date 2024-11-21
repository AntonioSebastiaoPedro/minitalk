/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:11:00 by ansebast          #+#    #+#             */
/*   Updated: 2024/11/21 23:15:57 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	check_pid(long pid)
{
	return (kill(pid, 0));
}

void	validate_client_args(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_puterror("Correct usage: ./client <pid_server> <string_to_send>\n",
			2);
	if (!ft_isint(argv[1]))
		ft_puterror("Invalid PID\n", 2);
	pid = ft_atol(argv[1]);
	if (pid <= 0 || check_pid(pid) != 0)
		ft_puterror("This PID does not correspond to any valid process\n", 2);
	if (ft_isempty(argv[2]))
		ft_puterror("Message cannot be empty\n", 2);
}

void	validate_server_args(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
		ft_puterror("Correct usage: ./server\n", 2);
}
