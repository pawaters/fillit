# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 06:55:05 by msilen            #+#    #+#              #
#    Updated: 2022/01/24 07:15:49 by msilen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

SRC = map.c \
	shifters.c \
	solver.c \
	valid.c \
	parser.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	@echo "Compiling"
	@$(CC) $(CFLAGS) $(SRC)
	@ar rcs $(NAME) $(OBJ)


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
