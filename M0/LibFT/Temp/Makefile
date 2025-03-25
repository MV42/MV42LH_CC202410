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

OBJS		=	$(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.o))

all: $(NAME)

$(NAME): extract_objs
	ar rcs $(NAME) $(OBJS)

extract_objs:
	@for dir in $(SUBDIRS); do \
		ar x $$dir/*.a; \
	done

clean:
	rm -f $(OBJS) $(NAME)

.PHONY: all clean