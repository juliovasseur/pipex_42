CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_lstdelone.c ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstiter.c ft_lstmap.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_isalpha.c ft_split.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_strlcat.c ft_memchr.c ft_memcmp.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_strtrim.c ft_strncmp.c ft_striteri.c ft_putnbr_fd.c ft_memmove.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_strjoin.c ft_substr.c ft_memcpy.c ft_strmapi.c

OBJ = ${SRC:.c=.o}

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -c -o $@

$(NAME) : ${OBJ}
	make -C ft_printf
	ar -rc  $(NAME) ${OBJ} ft_printf/libftprintf.a 

all : $(NAME)

clean :
	make -C ft_printf clean
	rm -f $(OBJ)

fclean : clean
	make -C ft_printf fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
