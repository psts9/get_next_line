# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthorell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 17:22:27 by pthorell          #+#    #+#              #
#    Updated: 2018/07/12 00:34:45 by pthorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

all: $(NAME)

$(NAME): $(wildcard *.c)
	gcc -c $^
	ar -rc libft.a *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f libft.a

re: fclean all

.PHONY: re fclean clean all
