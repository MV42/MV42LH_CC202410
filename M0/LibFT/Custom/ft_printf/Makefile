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

UTILS_PATH	=	./Utils/

SRCS		=	ft_printf.c \
				$(UTILS_PATH)ft_putnbr_base.c \
				$(UTILS_PATH)ft_printf_cspct.c \

NAME		=	ft_printf.a

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME) clean

$(NAME):	$(OBJS)
	@ar rcs $@ $^

clean:
	@rm -f $(OBJS)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
