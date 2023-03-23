# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 17:09:26 by jvasseur          #+#    #+#              #
#    Updated: 2022/11/24 14:58:07 by jvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr2.c ft_base.c ft_printf.c ft_printpct.c ft_printaddress.c

OBJ = $(SRC:.c=.o)


.c.o : $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	ar -rc  $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
