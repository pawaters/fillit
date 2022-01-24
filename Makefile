# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 06:55:05 by msilen            #+#    #+#              #
#    Updated: 2022/01/24 06:57:50 by msilen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -c -I ./includes

NAME = fillit

SRC = map.c \
		shifters.c \
		solver.c \
		valid.c \
		parser.c


SRC2 = $(SRC:%.c=%.o)

$(NAME): 
	@echo "Compiling"
	@$(CC) $(CFLAGS) $(SRC)
	@ar rcs $(NAME) $(SRC2)


clean:
	@echo "Deleting .o files..."
	@/bin/rm -f *.o

fclean: clean
	@echo "Cleaning up..."
	@/bin/rm -f $(NAME)

all: $(NAME)

re: fclean all
	@echo "Re-compiling..."
	@echo "OK!"
