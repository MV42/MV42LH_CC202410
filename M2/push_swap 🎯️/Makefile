# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 16:48:01 by ngaudoui          #+#    #+#              #
#    Updated: 2025/04/09 12:54:26 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME								=	push_swap

# Compiler settings
CC									=	gcc
CFLAGS								=	-Wall -Wextra -Werror -g -Iinclude/ -Ilib/libft
LDFLAGS								=	-Llib/libft
LIBS								=	-lft

# Directories
SRC_DIR								=	src/
CMD_DIR								=	$(SRC_DIR)commands/
OBJ_DIR								=	obj/
LIB_DIR								=	lib/
LIBFT_DIR							=	$(LIB_DIR)libft/

# Source files
SRC_FILES							=	handle_errors.c \
										init_a_to_b.c \
										init_b_to_a.c \
										push_swap.c \
										stack_init.c \
										stack_utils.c \
										split.c

CMD_FILES							=	push.c \
										rev_rotate.c \
										rotate.c \
										sort_stacks.c \
										sort_stacks_utils.c \
										sort_three.c \
										swap.c

# Object files
OBJ_FILES							=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES)) \
										$(patsubst %.c, $(OBJ_DIR)commands/%.o, $(CMD_FILES))

# Main target
all: $(NAME)

# Build binary
$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(LDFLAGS) $(LIBS) -o $@
	@echo "Compiled $(NAME)"

# Compile source files into object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)commands/%.o: $(CMD_DIR)%.c
	@mkdir -p $(OBJ_DIR)commands
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files and directory removed!"

fclean: clean
	@rm -rf $(NAME)
	@echo "Binaries removed!"

re: fclean all
	@echo "Project rebuilt!"

# Phony targets
.PHONY: all clean fclean re
