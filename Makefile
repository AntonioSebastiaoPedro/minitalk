# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 14:00:18 by ansebast          #+#    #+#              #
#    Updated: 2024/09/07 02:41:03 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g
SRC = ft_atol.c ft_isint.c ft_putnbr_fd.c validations.c \
	ft_isdigit.c  ft_putchar_fd.c  ft_putstr_fd.c \
	ft_isempty.c ft_puterror.c ft_strtol.c

OBJS = $(SRC:.c=.o)
CLIENT = client.c
SERVER = server.c
CLIENT_OBJS = $(CLIENT:.c=.o)
SERVER_OBJS = $(SERVER:.c=.o)

all: server client

server: $(OBJS) $(SERVER_OBJS)
	cc $(CFLAGS) $(OBJS) $(SERVER_OBJS) -o server 

client: $(OBJS) $(CLIENT_OBJS)
	cc $(CFLAGS) $(OBJS) $(CLIENT_OBJS) -o client 

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(OBJS)

fclean: clean
	rm -f server client

re: fclean all