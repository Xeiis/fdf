# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchristo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:26:37 by dchristo          #+#    #+#              #
#    Updated: 2015/12/26 16:30:27 by dchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = $(shell ls -1 | grep "\.c")

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(NAME) 
 
$(NAME): 
	@cd libft ; $(MAKE) -f Makefile
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
	@echo"+------------------------+";
	@echo"|  ______ _____  ______  |";
	@echo"| |  ____|  __ \|  ____| |";
	@echo"| | |__  | |  | | |__    |";
	@echo"| |  __| | |  | |  __|   |";
	@echo"| | |    | |__| | |      |";
	@echo"| |_|    |_____/|_|      |";
	@echo"|                        |";
	@echo"+------------------------+";
	
%.o : %.c
	$(CC) $(FLAGS) $< -o $@

clean:	
	rm -rf $(OBJS)
	@cd libft ; $(MAKE) clean -f Makefile

fclean:	clean
	rm -f $(NAME)
	@cd libft ; $(MAKE) fclean -f Makefile	
	
re:	fclean all

.PHONY: all clean fclean re
