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

NAME		=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Iget_next_line/ -Ift_printf/ -I.

OBJ_DIR		=	obj/
OBJ			=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRC))

SRC			=	$(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC) $(CUSTOM_SRC)

LIBFT_DIR	=	libft/
LIBFT_SRC	=	$(addprefix $(LIBFT_DIR)/, \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				)

CUSTOM_DIR	=	custom/
CUSTOM_SRC	=	$(addprefix $(CUSTOM_DIR)/, \
				ft_atoi_base.c \
				ft_isspace.c \
				ft_radtodeg.c \
				ft_degtorad.c \
				ft_abs.c \
				)

				
GNL_DIR		=	get_next_line/
GNL_SRC		=	$(addprefix $(GNL_DIR)/, \
				get_next_line.c \
				get_next_line_utils.c \
				)

PRINTF_DIR	=	ft_printf/
PRINTF_SRC	=	$(addprefix $(PRINTF_DIR)/, \
				ft_printf.c \
				ft_printf_cspct.c \
				ft_putnbr_base.c \
				)

all:	$(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "$(NAME) Created"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "OBJ Deleted"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(NAME) Deleted"

re:	fclean all

.PHONY: all clean fclean re
