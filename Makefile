# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/03 13:06:24 by mapearso          #+#    #+#              #
#    Updated: 2026/09/07 10:15:00 by mapearso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c \
	env_init.c \
	stack_ops.c \
	swap_op.c \
	push_op.c \
	rotate_op.c \
	reverse_rotate_op.c \
	simple.c \
	sort_three.c \
	sort_five.c \
	parse_input.c \
	printing.c \
	error_exit.c \
	adaptive.c \
	complex.c \
	medium.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
