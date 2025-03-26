# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 21:42:42 by mavander          #+#    #+#              #
#    Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
CC			=	gcc
MLX			=	mlx_linux
CFLAGS		=	-Wall -Wextra -Werror -Iinclude/ -I$(MLX)/ -Ilibft/ -g
LDFLAGS		=	-L$(MLX) -Llibft -lmlx_Linux -lm -lXext -lX11 -lz -lft

SRC_DIR		=	src/
OBJ_DIR		=	build/

SRC			=	build_map_utils.c \
				build_map.c \
				close_window.c \
				colors.c \
				draw_line.c \
				fdf.c \
				fill_map.c \
				rasterize.c \
				test.c \
				utils.c

OBJ			=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@
	@echo "$(NAME) created!"

$(OBJ): $(addprefix $(SRC_DIR), $(SRC))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<..."

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

re: fclean all

norm:
	@clear
	@norminette $(shell find . -type f \( -name "*.c" -o -name "*.h" \) ! -path "./$(MLX)/*")

.PHONY: all clean fclean re norm
