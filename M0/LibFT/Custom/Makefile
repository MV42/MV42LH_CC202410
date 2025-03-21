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

NAME		=	libcustom.a

MODULES		=	LIBFT \
				GNL \
				FT_PRINTF

LIBFT_DIR	=	LibFT/
GNL_DIR		=	GNL/
FT_PRINTF_DIR	=	ft_printf/

LIBFT_LIB	=	$(LIBFT_DIR)libft.a
GNL_LIB		=	$(GNL_DIR)gnl.a
FT_PRINTF_LIB	=	$(FT_PRINTF_DIR)libftprintf.a

LIBS		=	$(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)

OBJ_FILES	=	*.o

all:		$(NAME)

$(NAME):	$(MODULES)
	$(foreach lib,$(LIBS),ar -x $(lib);)
	ar rcs $(NAME) $(OBJ_FILES)
	rm -f $(OBJ_FILES)

LIBFT:
	$(MAKE) -C $(LIBFT_DIR)

GNL:
	$(MAKE) -C $(GNL_DIR)

FT_PRINTF:
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(foreach module,$(MODULES),$(MAKE) -C $($(module)_DIR) clean;)

fclean:		clean
	$(foreach module,$(MODULES),$(MAKE) -C $($(module)_DIR) fclean;)
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re $(MODULES)