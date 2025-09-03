# Project Name
NAME					=	philo

# Compiler Setting
CC						=	cc
CFLAG					=	-Wall -Wextra -Werror -g3

# Directory
SRC_DIR					=	src/
OBJ_DIR					=	obj/
INC_DIR					=	include/

# Source File
SRC						=	$(UTILS) $(FILES)

FILES_DIR				=	src/
FILES					=	$(addprefix $(FILES_DIR)/, \
							main.c \
							monitor.c \
							philo_actions.c \
							philo_states.c \
							philo_threads.c \
							sim_init.c \
							)

UTILS_DIR				=	src/utils
UTILS					=	$(addprefix $(UTILS_DIR)/, \
							libft.c \
							parse_args.c \
							print_status.c \
							utils.c \
							valid_arg.c \
							)

# Object File
OBJ						=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Include Flag
IFLAG					=	$(addprefix -I, $(INC_DIR))

# All Target
all: $(NAME)

# Main Target
$(NAME): $(OBJ)
	@$(CC) $(CFLAG) $(OBJ) -o $(NAME)
	@echo "Welcome $@ ! 🤩🤙"

# Object File Compilation Rule
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) $(IFLAG) -c $< -o $@
	@echo "Good Morning $(notdir $@) ! 👋😇"

# Mandatory Target
clean:
	@rm -rf $(OBJ_DIR)
	@echo "See You Soon $(OBJ_DIR) And Your Content... 🤧💔"

fclean: clean
	@rm -f $(NAME)
	@echo "Bye-Bye $(NAME) ! 🥺💋"

re: fclean all

# Phony Target
.PHONY: all clean fclean re
