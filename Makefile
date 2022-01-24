# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 06:55:05 by msilen            #+#    #+#              #
#    Updated: 2022/01/24 07:33:29 by msilen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft
SRCS = main.c map.c parser.c solver.c valid.c shifters.c
OBJS = *.o
LIB_DIR = libft/

$(NAME):
	make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -I $(INCLUDES) -L $(LIB_DIR) -lft

all: $(NAME)

clean:
	rm -rf $(OBJS)
	make -C $(LIB_DIR) fclean

fclean: clean
	rm -rf $(NAME)

re:	fclean all
