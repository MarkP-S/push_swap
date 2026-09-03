# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/03 13:06:24 by mapearso          #+#    #+#              #
#    Updated: 2026/09/03 13:06:24 by mapearso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = 	main.c \
		env_init.c \
		stack_ops.c \
		swap_op.c \
		push_op.c \
		rotate_op.c \
		reverse_rotate_op.c \
		strategies.c \
		testing_utils.c \
		simple.c \
		sort_three.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) libft

re: fclean all

.PHONY: all clean fclean re