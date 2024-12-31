# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 01:38:36 by firdawssema       #+#    #+#              #
#    Updated: 2024/07/25 17:07:51 by fimazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./includes -I./minilibx_opengl_20191021 -I./ft_printf/includes -I./ft_printf/libft/includes -g3 #-fsanitize=address
LDFLAGS = -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -L./ft_printf -lftprintf -L./ft_printf/libft -lft

# Sources
SRCS =  ./srcs/check_map.c \
		./utils/ft_strstr.c \
		./srcs/ismapvalid/exit.c \
		./srcs/ismapvalid/items.c \
		./srcs/ismapvalid/pos.c \
		./srcs/map.c \
		./srcs/ismapvalid/rectangle.c \
		./srcs/draw_map.c \
		./srcs/keypress.c \
		./srcs/move.c \
		./srcs/ismapvalid/ispath.c \
		./srcs/so_long.c \
		./srcs/draw_helper.c

OBJS = $(SRCS:.c=.o)

# Target
NAME = so_long

# Rules
all: message $(NAME)

message:
	echo "So long"

$(NAME): $(OBJS)
	$(MAKE) -C ./minilibx_opengl_20191021
	$(MAKE) -C ./ft_printf/libft
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(MAKE) -C ./minilibx_opengl_20191021 clean
	$(MAKE) -C ./ft_printf/libft clean
	$(MAKE) -C ./ft_printf clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./ft_printf/libft fclean
	$(MAKE) -C ./ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re message
