NAME = so_long
FILE = so_long.c\
		put_img.c\
		map.c\
		map_aux.c\
		game_move.c\
		validation.c\
		validation2.c\
		error.c\
		./validation3.c





CC = cc
FLAGS = -Wall -Wextra -Werror  
MINILIBX = ./minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm
LIBFT = ./libft/
LIBFT_A = $(LIBFT)libft.a
RM = rm -rf



all: $(NAME)

$(NAME):		
			$(MAKE) -C $(LIBFT)
			$(CC) $(FLAGS) $(FILE)  $(LIBFT_A) $(MINILIBX) -o $(NAME) 

clean:
		@$(MAKE) clean -C $(LIBFT)

fclean: clean
		@$(MAKE) fclean -C $(LIBFT)
		$(RM) $(NAME)	
re: fclean all


.PHONY: all clean re
