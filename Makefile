# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 17:59:29 by iassafe           #+#    #+#              #
#    Updated: 2023/05/04 11:08:42 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = 	mandatory/so_long.c \
		mandatory/so_long_utils.c \
		mandatory/parcing.c \
		mandatory/valid_path.c \
		mandatory/put_img.c \
		mandatory/so_long_utils2.c \
		mandatory/player.c \
		mandatory/move.c \
		mandatory/utils.c \
		mandatory/get_next_line.c \
		mandatory/get_next_line_utils.c
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = mandatory/so_long.h

SO_LONG_BONUS = so_long_bonus
SRC_BONUS = bonus/so_long_bonus.c \
			bonus/so_long_utils_bonus.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c \
			bonus/parcing_bonus.c \
			bonus/valid_path_bonus.c \
			bonus/so_long_utils2_bonus.c \
			bonus/player_bonus.c \
			bonus/move_bonus.c \
			bonus/move_enemy_bonus.c \
			bonus/utils_bonus.c \
			bonus/mlx_img_bonus.c
HEADER_BONUS = bonus/so_long_bonus.h

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(SO_LONG_BONUS)

so_long : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

so_long_bonus : $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(SO_LONG_BONUS)

mandatory/%.o : mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o : bonus/%.c $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(SO_LONG_BONUS)

re : fclean all
