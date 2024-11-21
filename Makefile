# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 14:00:18 by ansebast          #+#    #+#              #
#    Updated: 2024/11/21 23:26:06 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g

CLIENT = client.c functions_utils1.c  functions_utils2.c  validations.c
SERVER = server.c functions_utils1.c  functions_utils2.c  validations.c
CLIENT_OBJS = $(CLIENT:.c=.o)
SERVER_OBJS = $(SERVER:.c=.o)

CLIENT_BONUS = client_bonus.c functions_utils1_bonus.c  functions_utils2_bonus.c  validations_bonus.c
SERVER_BONUS = server_bonus.c functions_utils1_bonus.c  functions_utils2_bonus.c  validations_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

all: server client

server: $(SERVER_OBJS)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	cc $(CFLAGS) $(SERVER_OBJS) -o server 
	@echo "$(GREEN)Server executable $(NAME) created successfully!$(RESET)"

client: $(CLIENT_OBJS)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	cc $(CFLAGS) $(CLIENT_OBJS) -o client 
	@echo "$(GREEN)Client executable $(NAME) created successfully!$(RESET)"

bonus: client_bonus server_bonus

server_bonus: $(SERVER_BONUS_OBJS)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	cc $(CFLAGS) $(SERVER_BONUS_OBJS) -o server_bonus 
	@echo "$(GREEN)Bonus Server executable $(NAME) created successfully!$(RESET)"

client_bonus: $(CLIENT_BONUS_OBJS)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	cc $(CFLAGS) $(CLIENT_BONUS_OBJS) -o client_bonus 
	@echo "$(GREEN)Bonus Client executable $(NAME) created successfully!$(RESET)"

clean:
	@echo "$(RED)Removing all object files...$(RESET)"
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

fclean: clean
	@echo "$(RED)Removing the server and client executable ...$(RESET)"
	rm -f server client client_bonus server_bonus

re: fclean all

rebonus: re bonus