/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:11:00 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/11 23:21:39 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_pid(long pid)
{
	return (kill(pid, 0));
}

void	validate_client_args(int argc, char **argv)
{
        int     pid;
        
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
