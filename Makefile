# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#      									            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    										           #+#    #+#              #
#    										           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c map.c parser.c solver.c valid.c shifters.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -Wall -Werror -Wextra -c $(SRCS)
	gcc -Wall -Werror -Wextra -o $(NAME) $(OBJS) -L./libft -lft

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re:	fclean all
