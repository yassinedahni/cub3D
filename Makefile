# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 23:01:33 by ydahni            #+#    #+#              #
#    Updated: 2022/09/11 21:50:23 by ydahni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cub3D = cub3D
FLAGS = -Wextra -Wall -Werror -lmlx -framework OpenGL -framework AppKit
CC = cc
SRC = cub3D.c ./parsing/ft_split.c ./get_next_line/get_next_line.c \
	 ./get_next_line/get_next_line_utils.c ./parsing/parsing_utl.c \
	 ./parsing/new_map.c ./parsing/cub3D_check_all.c ./parsing/check_name_errors.c \
	 ./parsing/check_arg_in_map.c ./parsing/check_wall_in_map.c ./parsing/check_map_if_valid.c \
	 ./parsing/initialization.c \
	 ./parsing/check_map_zero.c ./parsing/check_map_W_E.c\
	 ./parsing/check_map_S_N.c ./parsing/check_map_F_C.c \
	 ./parsing/add_arg_in_map.c ./parsing/parsing_utl_2.c ./draw/check_image.c\
	 ./draw/DDA.c ./draw/draw_cub3d.c ./draw/Convert_RGB.c ./draw/check_position_of_player.c\
	 ./draw/texture.c ./draw/key.c ./draw/init_key.c\
	 

OBJ = ${SRC:.c=.o}

all : cub3D
	
$(cub3D): $(OBJ)
	$(CONTROL)	
	@$(CC) $(FLAGS) $(RDLINE) $(OBJ) -o cub3D
	@tput setaf 2; echo "cub3D IS READY"

clean :
	@rm -f $(OBJ)
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean
	@rm -f cub3D

re: fclean all 