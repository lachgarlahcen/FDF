
NAME = fdf

HDRS = -I./includes/



SRCS =		./src/main.c						\
			./src/draw.c						\
			./src/tools.c						\
			./src/keyhook.c	 					\
			./get_next_line/get_next_line.c		\

OBJS = *.o

LDFLAGS = -L./libft/

LFT = -lft

CC = gcc $(FLAGS)

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

# Rules

all: $(NAME)

$(NAME):	$(SRCS)
			@echo "\033[33m trying to compile files \033[0m"
			@$(CC) -c $(SRCS)
			@make  -C ./libft/
			@$(CC) $(HDRS)  $(OBJS) -L ./libft/ $(LFT) $(MLX) -o $(NAME)
			@echo "\033[31m Files compiled  \n\033[0m"


clean:
	@make clean -C ./libft/
	@echo "\033[33m cleaning *.o files \033[0m"
	@rm -f $(OBJS)
	@echo "\033[31m Files .o deleted \n\033[0m"

fclean: clean
	@make fclean -C ./libft/
	@echo "\033[33m Clean All Compiled Files ..\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m $(NAME) deleted\n\033[0m"

re: fclean all

