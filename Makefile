# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:55:40 by kkido             #+#    #+#              #
#    Updated: 2025/08/06 14:48:44 by kkido            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c \


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx-linux
LIBS = -Llibft -lft -Lminilibx-linux -lmlx -lX11 -lXext -lm

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a minilibx-linux/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libft/libft.a:
	make -C libft

minilibx-linux/libmlx.a:
	make -C minilibx-linux

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
