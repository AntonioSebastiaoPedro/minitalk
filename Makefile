# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 14:00:18 by ansebast          #+#    #+#              #
#    Updated: 2024/09/11 22:54:00 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g
SRC = ft_atol.c ft_isint.c ft_putnbr_fd.c validations.c \
	ft_isdigit.c  ft_putchar_fd.c  ft_putstr_fd.c \
	ft_isempty.c ft_puterror.c ft_strtol.c

OBJS = $(SRC:.c=.o)
CLIENT_BONUS = client_bonus.c
CLIENT = client.c
SERVER = server.c
SERVER_BONUS = server_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS:.c=.o)
CLIENT_OBJS = $(CLIENT:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS:.c=.o)
SERVER_OBJS = $(SERVER:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

all: server client

server: $(OBJS) $(SERVER_OBJS)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	cc $(CFLAGS) $(OBJS) $(SERVER_OBJS) -o server 
	@echo "$(GREEN)Server executable $(NAME) created successfully!$(RESET)"

client: $(OBJS) $(CLIENT_OBJS)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	cc $(CFLAGS) $(OBJS) $(CLIENT_OBJS) -o client 
	@echo "$(GREEN)Client executable $(NAME) created successfully!$(RESET)"

bonus: client_bonus server_bonus

server_bonus: $(OBJS) $(SERVER_BONUS_OBJS)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	cc $(CFLAGS) $(OBJS) $(SERVER_BONUS_OBJS) -o server_bonus 
	@echo "$(GREEN)Bonus Server executable $(NAME) created successfully!$(RESET)"

client_bonus: $(OBJS) $(CLIENT_BONUS_OBJS)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	cc $(CFLAGS) $(OBJS) $(CLIENT_OBJS) -o client_bonus 
	@echo "$(GREEN)Bonus Client executable $(NAME) created successfully!$(RESET)"

clean:
	@echo "$(RED)Removing all object files...$(RESET)"
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS) $(OBJS)

fclean: clean
	@echo "$(RED)Removing the server and client executable ...$(RESET)"
	rm -f server client client_bonus server_bonus

re: fclean all

rebonus: re bonus