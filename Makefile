# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmelag <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 11:47:49 by carmelag          #+#    #+#              #
#    Updated: 2025/01/28 11:47:55 by carmelag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = so_long

# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Librerías necesarias
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

# Archivos fuente y objetos
SRCS = \
	main.c \
	ft_memset.c \
	read_map.c \
	check_map.c \
	validate_map_elements.c \
	free_map.c \
	move_player.c \
	render_game.c \
	load_images.c \
	press_key.c \
	ft_exit.c

OBJS = $(SRCS:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
