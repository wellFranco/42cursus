NAME = so_long
FILE = so_long.c




CC = cc
FLAGS = -Wall -Wextra -Werror  -o 
MINILIBX = ./minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm
RM = rm -rf



all: $(NAME)

$(NAME):		
			$(CC) $(FLAGS) $(NAME) $(FILE) $(MINILIBX) 

clean:
		$(RM) $(NAME)

fclean: clean
			
re: clean all


.PHONY: all clean re