# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 06:55:05 by msilen            #+#    #+#              #
#    Updated: 2022/01/24 07:24:56 by msilen           ###   ########.fr        #
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

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

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
