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

# Project name
NAME			=	fdf

# Compiler settings
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3

# Directories
LIB_DIR			=	lib/
SRC_DIR			=	src/
OBJ_DIR			=	obj/
INC_DIR			=	include/

# Library paths
MLX_DIR			=	$(LIB_DIR)minilibx_linux/
LIBFT_DIR		=	$(LIB_DIR)libft/

# Source files
SRC				=	alloc_tab.c \
					build_tab_utils.c \
					build_tab.c \
					color_utils.c \
					draw_map_utils.c \
					draw_map.c \
					fdf.c \
					fill_tab.c \
					hooks.c \
					rasterize.c \
					window.c \
					zoom.c

# Object files
OBJS			=	$(SRC:%.c=$(OBJ_DIR)%.o)

# Include and library flags
IFLAGS			=	$(addprefix -I, $(INC_DIR) $(MLX_DIR) $(LIBFT_DIR))
LFLAGS			=	$(addprefix -L, $(LIBFT_DIR) $(MLX_DIR))
LIBS			=	-lmlx_Linux -lm -lXext -lX11 -lz -lft

# Main target
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) -o $(NAME)

# Object file compilation rule
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Targets
all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(OBJ_DIR) And Its Content Has Been Deleted !"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) Removed !"

re: fclean all
	@echo "FdF Has Been Remade !"

# Phony targets
.PHONY: all clean fclean re libft mlx