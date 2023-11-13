# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:32:16 by wfranco           #+#    #+#              #
#    Updated: 2023/11/09 15:35:12 by wfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c\
       ft_printptr.c\
       ft_putchar.c\
       ft_puthexa.c\
       ft_putnbr.c\
       ft_putstr.c\
       ft_putunsint.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(OBJ): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

