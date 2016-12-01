# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 16:54:45 by thbricqu          #+#    #+#              #
#    Updated: 2016/11/22 16:54:47 by thbricqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC_C = ./src/
SRC	= src/test_error.c \
		src/read_file.c \
		src/list.c \
		src/ft_sqrt.c \
		src/ft_resolve.c \
		src/main.c \
		src/ft_putchar.c \
		src/ft_putstr.c \
		src/ft_memalloc.c \
		src/ft_memset.c \
		src/ft_memdel.c \
		src/ft_strnew.c \
		src/ft_strclr.c \
		src/ft_test_error_2.c \
		src/ft_map.c \
		src/ft_strlen.c
OBJ		= $(patsubst src/%.c,./%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME)
./%.o: src/%.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@/bin/rm -rf *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all


.PHONY: clean fclean re all