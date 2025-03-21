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

NAME		=	GNL.a

CFLAGS		=	-Wall -Wextra -Werror

FILES		=	get_next_line_utils.c \
				get_next_line.c \

OBJ			=	$(FILES:.c=.o)
BONUS_OBJ	=	$(BONUS_FILES:.c=.o)
RM			=	rm -f

$(NAME):	$(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "$@ created"
	@ranlib $@
	@echo "$@ indexed"

$(OBJ):
	@cc -c $(FLAG) $(FILES)
	@echo "Mandatory files compiled into objects"

all:		$(NAME)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@echo "OBJ deleted"

fclean:		clean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re:			fclean all

bonus:		$(BONUS_FILES)
	@cc -c $(FLAG) $(BONUS_FILES)
	@echo "Bonus files compiled into objects"
	@ar rcs $(NAME) $(BONUS_OBJ)
	@echo "$@ created"
	@ranlib $(NAME)
	@echo "$@ indexed"

.PHONY: all, clean, fclean, re, bonus
