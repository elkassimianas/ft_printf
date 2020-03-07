# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 16:39:44 by ael-kass          #+#    #+#              #
#    Updated: 2019/12/25 15:43:31 by ael-kass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c

OBJS = *.o

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
