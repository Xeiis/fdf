# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by ybarbier          #+#    #+#              #
#    Updated: 2015/12/27 18:16:56 by dchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-missing-noreturn \
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls \
		  -Wmissing-declarations

SRC =	main.c \

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;34m";
	@echo "+------------------------+";
	@echo "|  ______ _____  ______  |";
	@echo "| |  ____|  __ \|  ____| |";
	@echo "| | |__  | |  | | |__    |";
	@echo "| |  __| | |  | |  __|   |";
	@echo "| | |    | |__| | |      |";
	@echo "| |_|    |_____/|_|      |";
	@echo "|                        |";
	@echo "+-----------by dchristo--+";

.PHONY: clean fclean re all

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
