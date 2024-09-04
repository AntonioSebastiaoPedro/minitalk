# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 14:00:18 by ansebast          #+#    #+#              #
#    Updated: 2024/09/04 14:19:20 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
LIBFT = libft.a
CFLAGS = -Wall -Werror -Wextra
SRC = client.c server.c
OBJS = $(SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT): $(OBJS)
	ar rcs $(LIBFT) $(OBJS)

$(SERVER): $(LIBFT) $(OBJS)
	CC $(CFLAGS) -o $(SERVER) $(OBJS) -L. -lft

$(CLIENT): $(LIBFT) $(OBJS)
	cc $(CFLAGS) $(CLIENT) $(OBJS) -L. -lft

%.c:%.o:
	cc $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(LIBFT)

re: fclean all