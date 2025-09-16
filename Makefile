# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:55:40 by kkido             #+#    #+#              #
#    Updated: 2025/08/21 14:52:24 by kkido            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c error_handling.c handle_map.c


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx_mms_20191025_beta
 LIBS = -Llibft -lft -Lminilibx_mms_20191025_beta -lmlx -framework OpenGL -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	make -C minilibx_mms_20191025_beta
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
