# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:55:40 by kkido             #+#    #+#              #
#    Updated: 2025/09/16 14:32:22 by kkido            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c error_handling.c handle_map.c


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx-linux
LIBS = -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libft/libft.a:
	make -C libft

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
