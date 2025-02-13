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
MLX			=	MLX
CFLAGS		=	-Wall -Wextra -Iinclude/ -I$(MLX)/ -g
LDFLAGS		=	-L$(MLX) -lmlx_Linux -lm -lXext -lX11 -lz

C_P			=	C/
C			=	$(C_P)FdF.c \
				$(C_P)1.c \
				$(C_P)2.c

O_P			=	O/
O			=	$(addprefix $(O_P), $(notdir $(C:.c=.o)))

$(NAME): $(O)
	@$(CC) $(O) $(LDFLAGS) -o $@
	@echo "$(notdir $@) Created !"

all: $(NAME)

$(O_P)%.o: $(C_P)%.c
	@mkdir -p $(O_P)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(notdir $@) Created !"

clean:
	@rm -rf $(O_P)
	@echo "Object Files Removed !"

fclean: clean
	@rm -rf $(NAME)
	@echo "FdF Removed !"

re: fclean all

.PHONY: all clean fclean re