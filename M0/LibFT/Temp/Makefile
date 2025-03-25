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

SUBDIRS		=	baselibft \
				ft_printf \
				get_next_line \
				utils \

NAME		=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	-I../include

-include sources.mk

OBJS		=	$(SRCS:.c=.o)

all: gen_sources $(NAME)

gen_sources:
	@./generate_sources.sh

$(NAME): $(OBJS) submodules
	@ar rcs $@ $(OBJS)
	@for dir in $(SUBDIRS); do \
		if [ -f $$dir/lib$$dir.a ]; then \
			ar rcs $(NAME) $$dir/lib$$dir.a; \
		fi \
	done

submodules:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	@rm -f $(NAME)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

.PHONY: all clean fclean re submodules gen_sources
