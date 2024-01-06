# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 14:29:36 by wfranco           #+#    #+#              #
#    Updated: 2024/01/06 14:41:22 by wfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minitalk

CLIENT =	client

SERVER =	server

CC =		cc

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -rf

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):
		$(CC) $(CFLAGS) -o $(CLIENT) client.c minitalk_utils.c

$(SERVER):
		$(CC) $(CFLAGS) -o $(SERVER) server.c minitalk_utils.c

clean:
		$(RM) $(CLIENT) && $(RM) $(SERVER)

fclean: clean
		clear

re: fclean all

.PHONY: all clean fclean re
