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
CLIENT								=	client
SERVER								=	server
NAME								=	$(CLIENT) $(SERVER)

CLIENT_BONUS						=	client_bonus
SERVER_BONUS						=	server_bonus
NAME_BONUS							=	$(CLIENT_BONUS) $(SERVER_BONUS)

# Compiler settings
CC									=	cc
CFLAGS								=	-Wall -Wextra -Werror \
										-g3 \
										# -MMD

# Directories
SRC_DIR								=	src/
INC_DIR								=	include/
LIB_DIR								=	lib/
OBJ_DIR								=	obj/

# Library paths
LIBFT_DIR							=	$(LIB_DIR)libft/

# Source files
SRC_CLIENT							=	client.c
SRC_SERVER							=	server.c
SRC_UTILS							=	utils.c

SRC_CLIENT_BONUS					=	client_bonus.c
SRC_SERVER_BONUS					=	server_bonus.c
SRC_UTILS_BONUS						=	utils_bonus.c

# Object files
OBJ_CLIENT							=	$(OBJ_DIR)utils.o $(OBJ_DIR)client.o
OBJ_SERVER							=	$(OBJ_DIR)utils.o $(OBJ_DIR)server.o

OBJ_CLIENT_BONUS					=	$(OBJ_DIR)utils_bonus.o $(OBJ_DIR)client_bonus.o
OBJ_SERVER_BONUS					=	$(OBJ_DIR)utils_bonus.o $(OBJ_DIR)server_bonus.o

# Include and library flags
IFLAGS								=	$(addprefix -I, $(INC_DIR) $(LIBFT_DIR))
LFLAGS								=	$(addprefix -L, $(LIBFT_DIR))
LIBS								=	-lft

# Main target
all: $(NAME)

bonus: $(NAME_BONUS)

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

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LFLAGS) $(LIBS) -o $(CLIENT_BONUS)
	@echo "Compiled $(CLIENT_BONUS)"

$(SERVER_BONUS): $(OBJ_SERVER_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LFLAGS) $(LIBS) -o $(SERVER_BONUS)
	@echo "Compiled $(SERVER_BONUS)"

# Clean Rules
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files and directory removed!"

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "Binaries removed!"

re: fclean all
	@echo "Project rebuilt!"

# # Include dependency files
# -include $(OBJ:.o=.d)
# -include $(OBJ_BONUS:.o=.d)

# Phony targets
.PHONY: all bonus clean fclean re