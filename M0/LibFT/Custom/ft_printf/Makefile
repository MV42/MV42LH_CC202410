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

NAME		=	ft_printf.a

UTILS_PATH	=	./Utils/

SRC			=	ft_printf.c \
				$(UTILS_PATH)ft_putnbr_base.c \
				$(UTILS_PATH)ft_printf_cspct.c

AR			=	ar rcs

OBJS		=	$(SRC:.c=.o)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re, bonus
