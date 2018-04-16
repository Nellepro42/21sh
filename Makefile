# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neprocur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 23:31:23 by neprocur          #+#    #+#              #
#    Updated: 2017/07/17 01:07:17 by neprocur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
SRC = ./21sh.c ./get_next_line.c check.c ft_all.c ft_builtins.c ft_cd.c \
	  ft_next.c ft_set.c ft_search.c ft_setenv.c ft_update_env.c 

LIBFT = libft/libft.a
CC = gcc
LFLAGS = -L libft/ -lft
FLAG = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAG) $(LFLAGS)  -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c ./ft_21sh.h
	@$(CC) -o $@ -c $< $(FLAGS)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

.PHONY: clean fclean

re: fclean all
