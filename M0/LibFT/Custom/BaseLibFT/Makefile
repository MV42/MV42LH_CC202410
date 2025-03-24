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

SUBDIRS		=	Additional \
				Bonus \
				Libc \

NAME		=	BaseLibFT.a

all:		$(NAME) clean

$(NAME):	$(SUBDIRS:%=%.a)
	@echo "Création de la bibliothèque globale $(NAME)"
	@ar rcs $@ $(foreach dir,$(SUBDIRS),$(dir)/$(dir).a)

%.a:
	@echo "Compilation dans le sous-dossier $*"
	@$(MAKE) -C $*

clean:
	@$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) fclean;)
	@echo "Subfolders Residual Files Removed !"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(NAME) Removed !"

re:			fclean all

.PHONY: clean fclean re all
