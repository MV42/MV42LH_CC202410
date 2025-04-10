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
NAME								=	$(CLIENT) $(SERVER)
CLIENT								=	client
SERVER								=	server

# Compiler settings
CC									=	cc
CFLAGS								=	-Wall -Wextra -Werror \
										-g3 \

# Directories
SRC_DIR								=	src/
INC_DIR								=	include/
LIB_DIR								=	lib/
OBJ_DIR								=	obj/

# Library paths
LIBFT_DIR							=	$(LIB_DIR)libft/

# Source files
SRC_CLIENT							=	utils.c client.c
SRC_SERVER							=	utils.c server.c

SRC_CLIENT_BONUS					=	utils_bonus.c client_bonus.c
SRC_SERVER_BONUS					=	utils_bonus.c server_bonus.c

# Object files
OBJ_CLIENT							=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_CLIENT_USED))
OBJ_SERVER							=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_SERVER_USED))

# Include and library flags
IFLAGS								=	$(addprefix -I, $(INC_DIR) $(LIBFT_DIR))
LFLAGS								=	$(addprefix -L, $(LIBFT_DIR))
LIBS								=	-lft

# Compilation Mode (Mandatory / Bonus)
ifneq (,$(filter bonus client_bonus server_bonus,$(MAKECMDGOALS)))
	SRC_CLIENT_USED = $(SRC_CLIENT_BONUS)
	SRC_SERVER_USED = $(SRC_SERVER_BONUS)
else
	SRC_CLIENT_USED = $(SRC_CLIENT)
	SRC_SERVER_USED = $(SRC_SERVER)
endif

# Main target
all: $(NAME)

bonus: $(NAME)
client_bonus: $(CLIENT)
server_bonus: $(SERVER)

# Compilation Rules
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LFLAGS) $(LIBS) -o $(CLIENT)
	@echo "Compiled $(CLIENT)"

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LFLAGS) $(LIBS) -o $(SERVER)
	@echo "Compiled $(SERVER)"

# Clean Rules
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files and directory removed!"

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "Binaries removed!"

re: fclean all
	@echo "Project rebuilt!"

# Phony targets
.PHONY: all bonus clean fclean re
