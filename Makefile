#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/23 17:44:08 by myarovoy          #+#    #+#              #
#    Updated: 2018/09/23 17:44:10 by myarovoy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = myarovoy.filler

CFLAGS = -Wall -Wextra -Werror
CFLAGS_INC = -I includes/
LIB = libft.a 

FILES = main.c 			\
		getting_next.c 	\
		clear_input.c	\
		parsing.c

.PHONY = all clean fclean clean re

FILLERSRCS	= $(addprefix src/, $(FILES))

OBJ = $(FILLERSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $(CFLAGS_INC) $< -o $@

$(NAME): $(OBJ)
	@make -f makefile.libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[32mCreated myarovoy.filler, Object Files and Library\033[0m"

clean:
	@rm -rf $(OBJ) $(LIBOBJ)
	@make -f makefile.libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -f makefile.libft fclean
	@echo "\033[32mRemoved myarovoy.filler, Object Files and Library\033[0m"

re: fclean all
