# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:55:22 by joseanto          #+#    #+#              #
#    Updated: 2024/06/06 17:34:34 by wfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ASSISTANT = ./assistant/
COMMANDS = ./commands/
ARGUMENTS = ./argument_management/
FILE =	minishell.c\
	$(ASSISTANT)len.c\
	$(ASSISTANT)ft_strtrim.c\
	$(ASSISTANT)ft_split.c\
	$(ASSISTANT)skip_str.c\
	$(ASSISTANT)copy.c\
	$(ASSISTANT)search.c\
	$(ASSISTANT)list_operations.c\
	$(ASSISTANT)ft_itoa.c\
	$(ASSISTANT)ft_atoi.c\
	$(ASSISTANT)error_message.c\
	$(ASSISTANT)syntax_redirect.c\
	$(ARGUMENTS)environment_variable.c\
	$(ARGUMENTS)argument_management.c\
	$(ARGUMENTS)quotes.c\
	$(ARGUMENTS)pipe.c\
	$(ARGUMENTS)bigger_then.c\
	$(ARGUMENTS)bigger_bigger_than.c\
	$(ARGUMENTS)less_than.c\
	$(ARGUMENTS)smaller_smaller_than.c\
	$(ARGUMENTS)redirection_operators.c\
	$(ARGUMENTS)signal.c\
	$(COMMANDS)add_variable.c\
	$(COMMANDS)echo.c\
	$(COMMANDS)cd.c\
	$(COMMANDS)pwd.c\
	$(COMMANDS)export.c\
	$(COMMANDS)unset.c\
	$(COMMANDS)env.c\
	$(COMMANDS)exit.c\
	$(COMMANDS)exec_program.c\
	$(COMMANDS)commands.c
CC = cc
FLAGS = -Wall -Wextra -Werror -o
READLINE = -lreadline
NAME = minishell
RM = rm

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(NAME) $(FILE) $(READLINE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re