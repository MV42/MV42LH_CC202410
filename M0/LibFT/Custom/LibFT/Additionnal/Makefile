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

NAME		=	additionnal.a

SRC			=	ft_itoa.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_substr.c \

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
