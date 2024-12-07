# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: incalero <incalero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 10:49:52 by auskola-          #+#    #+#              #
#    Updated: 2024/06/27 13:58:56 by incalero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_BONUS = cub3d_bonus

CC = gcc 

CFLAGS =  -Wall -Wextra -Werror -g3 #-fsanitize=address 

MLXFLAGS = libmlx.a -lX11 -lXext -lm 

# MLXFLAGS =  -lbsd -Imlx -lXext -lX11 

MLX_DIR = minilibx-linux
MLX = libmlx.a
MLXFLAGS = $(MLX) -lX11 -lXext -lm

SRC_FILES = src/main.c src/get_next_line_util.c src/get_next_line.c src/load.c src/functions.c \
	src/debug.c src/check_map.c src/ft_itoa.c src/ft_strtrim.c src/keyboard.c src/keyboard2.c \
	src/options3d.c src/ft_error.c src/texturas.c src/memory.c src/memory2.c src/ft_paint2.c \
	src/ft_paint.c src/ft_animations.c src/ft_start_positions.c src/alturas.c src/ft_split.c \
	src/options3d2.c src/functions2.c src/main2.c src/main3.c src/check_map2.c \
	src/check_map3.c src/check.c src/debug2.c src/debug3.c src/load2.c 

# MLXFLAGS = -framework OpenGL -framework AppKit

SRC_BONUS_FILES = src/bonus/main_bonus.c src/bonus/get_next_line_util_bonus.c src/bonus/get_next_line_bonus.c src/bonus/load_bonus.c src/bonus/functions_bonus.c \
	src/bonus/debug_bonus.c src/bonus/check_map_bonus.c src/bonus/ft_itoa_bonus.c src/bonus/ft_strtrim_bonus.c src/bonus/keyboard_bonus.c src/bonus/keyboard2_bonus.c \
	src/bonus/options3d_bonus.c src/bonus/ft_error_bonus.c src/bonus/texturas_bonus.c src/bonus/memory_bonus.c src/bonus/memory2_bonus.c src/bonus/ft_paint2_bonus.c \
	src/bonus/ft_paint_bonus.c src/bonus/ft_animations_bonus.c src/bonus/ft_start_positions_bonus.c src/bonus/alturas_bonus.c src/bonus/ft_split_bonus.c \
	src/bonus/options3d2_bonus.c src/bonus/functions2_bonus.c src/bonus/main2_bonus.c src/bonus/main3_bonus.c src/bonus/check_map2_bonus.c \
	src/bonus/check_map3_bonus.c src/bonus/check_bonus.c src/bonus/debug2_bonus.c src/bonus/debug3_bonus.c src/bonus/load2_bonus.c 

INCLUDE = src/cube3d.h src/get_next_line.h 

INCLUDE_BONUS = src/bonus/cube3d_bonus.h src/bonus/get_next_line_bonus.h 

OBJS = $(SRC_FILES:.c=.o)

OBJS_BONUS = $(SRC_BONUS_FILES:.c=.o)

all: $(NAME)

$(MLX):
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) $(MLX)

$(NAME): $(OBJS) $(INCLUDE) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(INCLUDE_BONUS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXFLAGS) -o $(NAME_BONUS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(MLX)


fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(MLX)


re: fclean all

.PHONY: all clean fclean re bonus
