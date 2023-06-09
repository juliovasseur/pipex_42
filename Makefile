# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 17:09:26 by jvasseur          #+#    #+#              #
#    Updated: 2023/03/31 18:14:42 by jvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang -gdwarf-4 -g 

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

NAME_BONUS = pipex

SRC = src/child.c src/msg_error.c src/open_files.c src/free.c src/pipex.c src/get_path.c src/help_free.c src/utils.c

SRC_BONUS = src_bonus/child_bonus.c src_bonus/msg_error_bonus.c src_bonus/open_files_bonus.c src_bonus/free_bonus.c src_bonus/here_doc_bonus.c src_bonus/pipex_bonus.c

MAKE = make -C

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME) : $(OBJ)
	$(MAKE) Libft
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -LLibft -lft -LLibft/ft_printf -lftprintf

bonus : ${OBJ_BONUS}
	$(MAKE) Libft
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME_BONUS) -LLibft -lft -LLibft/ft_printf -lftprintf
	
all : $(NAME)

clean :
	make -C Libft clean
	rm -f $(OBJ) ${OBJ_BONUS}

fclean : clean
	make -C Libft fclean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re
