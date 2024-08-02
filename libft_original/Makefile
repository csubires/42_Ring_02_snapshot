#/* ************************************************************************** */
#/*                                                                            */
#/*                                                        :::      ::::::::   */
#/*   Makefile                                           :+:      :+:    :+:   */
#/*                                                    +:+ +:+         +:+     */
#/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
#/*                                                +#+#+#+#+#+   +#+           */
#/*   Created: 2024/04/10 16:37:51 by csubires          #+#    #+#             */
#/*   Updated: 2024/04/22 15:48:59 by csubires         ###   ########.fr       */
#/*                                                                            */
#/* ************************************************************************** */

NAME		= libft.a
HEADER		= libft.h
CC			= cc
CFLAGS 		= -Wall -Werror -Wextra -I$(H_FILES)
H_FILES		= .
O_DIR		= obj
O_FILES = $(addprefix $(O_DIR)/,$(C_FILES:%.c=%.o))
O_BONUS = $(addprefix $(O_DIR)/,$(C_BONUS:%.c=%.o))
C_FILES	= ft_isalpha.c \
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c	\
			ft_memset.c	\
			ft_bzero.c	\
			ft_memcpy.c	\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c	\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_memchr.c	\
			ft_memcmp.c	\
			ft_strnstr.c	\
			ft_atoi.c	\
			ft_calloc.c	\
			ft_strdup.c	\
			ft_substr.c	\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c	\
			ft_itoa.c	\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c

C_BONUS	= ft_lstnew.c	\
			ft_lstadd_front.c	\
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c	\
			ft_lstdelone.c	\
			ft_lstclear.c	\
			ft_lstiter.c	\
			ft_lstmap.c

# --------------------------------------

$(shell	mkdir -p $(O_DIR))

all:		$(NAME)

$(NAME):	$(O_FILES)
	@echo "BULDING:\t$(NAME)"
	@ar -crs $(NAME) $(O_FILES)

$(O_FILES):	$(C_FILES)
	@echo "BULDING:\t$(@:obj/%.o=%.c)	->	$@"
	@$(CC) $(CFLAGS) -c $(@:obj/%.o=%.c) -o $@

bonus:		$(NAME) $(O_BONUS)
	@echo "BULDING BONUS:\t$(NAME)"
	@ar -crs $(NAME) $(O_BONUS)

$(O_BONUS): $(C_BONUS)
	@echo "BULDING BONUS:\t$(@:obj/%.o=%.c)	->	$@"
	@$(CC) $(CFLAGS) -c $(@:obj/%.o=%.c) -o $@

clean:
		clear
		@rm -fr $(O_DIR) *.o
fclean:
		@rm -f $(NAME)
re: | fclean $(NAME)

# --------------------------------------

aclean:	| clean	fclean

print:
		@echo "\nNAME LIB:\n\t$(NAME)"
		@echo "\nSOURCES:\n\t$(C_FILES)"
		@echo "\nOBJECTS:\n\t$(O_FILES)\n"
		@echo "\nSOURCES BONUS:\n\t$(C_BONUS)"
		@echo "\nOBJECTS BONUS:\n\t$(O_BONUS)\n"
		@nm --print-armap $(NAME) 2>/dev/null ; true

norm:
		@norminette -R CheckForbiddenSourceHeader $(C_FILES) $(C_BONUS) $(HEADER) 2>/dev/null ; true

.PHONY: all, clean, fclean, re, bonus, aclean, print, norm
