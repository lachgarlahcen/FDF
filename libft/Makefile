# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atafah <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 14:47:48 by atafah            #+#    #+#              #
#    Updated: 2018/10/27 18:26:48 by atafah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c *.c
	@ar rc $(NAME) *.o

clean :
	@rm -f *.o

fclean : clean
	@rm -f $(NAME)

re : fclean all
