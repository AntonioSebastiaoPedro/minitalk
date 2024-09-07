/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:20:27 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/07 01:07:58 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

long int	ft_strtol(char *str, char **endptr);
long		ft_atol(const char *str);
void		ft_putnbr_fd(long n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_puterror(char *msg, int fd);
void		validate_arguments(int argc, char **argv);
int			ft_isdigit(int ch);
int			ft_isint(char *str);
int			ft_isempty(char *str);
int			check_pid(long pid);

#endif