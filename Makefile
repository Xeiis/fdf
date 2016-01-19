# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by ybarbier          #+#    #+#              #
#    Updated: 2016/01/19 13:11:36 by dchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_INC = ./libft/

CC = gcc

CFLAGS	= -Wall -Wextra -Werror# -ansi -pedantic -Wshadow -Wno-missing-noreturn \
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls \
		  -Wmissing-declarations

SRC = $(shell ls -1 | grep "\.c")

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@echo "\033[0m";
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJS) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;5;1;36m";
	@echo "+------------------------+";
	@echo "|  ______ _____  ______  |";
	@echo "| |  ____|  __ \|  ____| |";
	@echo "| | |__  | |  | | |__    |";
	@echo "| |  __| | |  | |  __|   |";
	@echo "| | |    | |__| | |      |";
	@echo "| |_|    |_____/|_|      |";
	@echo "|                        |";
	@echo "+-----------by dchristo--+";
	@echo "\033[0m";

.PHONY: clean fclean re all

clean:
	make -C libft/ clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
