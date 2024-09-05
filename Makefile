# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 14:00:18 by ansebast          #+#    #+#              #
#    Updated: 2024/09/04 17:30:58 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CLIENT = client.c
SERVER = server.c
COBJS = $(CLIENT:.c=.o)
SOBJS = $(SERVER:.c=.o)

all: server client

server: $(SOBJS)
	cc $(CFLAGS) $(SOBJS) -o server 

client: $(COBJS)
	cc $(CFLAGS) $(COBJS) -o client 

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SOBJS) $(COBJS)

fclean: clean
	rm -f server client

re: fclean all