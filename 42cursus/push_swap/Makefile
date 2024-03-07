# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 16:39:09 by wfranco           #+#    #+#              #
#    Updated: 2024/03/07 16:39:14 by wfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUX = ./'aux_utils'/
OPERATION = ./'operations'/
ALGORITHM = ./algorithm/
FILE = push_swap.c\
		$(AUX)insert_stack.c\
		$(AUX)remove_stack.c\
		$(AUX)func_assist1.c\
		$(AUX)func_assist2.c\
		$(AUX)utils1.c\
		$(AUX)utils2.c\
		$(AUX)utils3.c\
		$(OPERATION)operations1.c\
		$(OPERATION)operations2.c\
		$(OPERATION)operations3.c\
		$(ALGORITHM)algorithm1.c\
		$(ALGORITHM)algorithm2.c
NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -o
RM = rm

all: $(NAME) $(OBJS)

$(NAME):
		$(CC) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

.PHONY: all clean re

