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
BASIC_NAME = basic

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
	strategies.c \
	testing_utils.c \
	simple.c \
	sort_three.c \
	parse_input.c \
	printing.c

OBJ = $(SRC:.c=.o)

BASIC_SRC = main.c \
	env_init.c \
	stack_ops.c \
	swap_op.c \
	push_op.c \
	rotate_op.c \
	reverse_rotate_op.c \
	testing_utils.c \
	simple.c \
	printing.c

BASIC_OBJ = $(BASIC_SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

basic: $(LIBFT) $(BASIC_OBJ)
	$(CC) $(CFLAGS) $(BASIC_OBJ) -L$(LIBFT_DIR) -lft -o $(BASIC_NAME)

clean:
	rm -f $(OBJ) $(BASIC_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BASIC_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all basic clean fclean re
