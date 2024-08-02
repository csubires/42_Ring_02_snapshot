# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csubires <csubires@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 08:45:48 by csubires          #+#    #+#              #
#    Updated: 2024/06/21 09:38:42 by csubires         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_SRV	= server.c
C_CLN	= client.c
C_BSRV	= server_bonus.c
C_BCLN	= client_bonus.c

LIBFT_FILE = libft/libft.a

CC			= clang
H_FILES		= .
CFLAGS 		= -Wall -Werror -Wextra -I$(H_FILES)
PRINT		= echo
GREEN		= \033[0;32m
YELLOW		= \033[1;33m
ENDC		= \033[0m
MAKEFLAGS	+= --no-print-directory

# --------------------------------------

all:	server client

server:	$(C_SRV) $(LIBFT_FILE)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<	->	$@"
	@$(CC) $(CFLAGS) $< -o $@ -L. -l:$(LIBFT_FILE)

client:	$(C_CLN) $(LIBFT_FILE)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<	->	$@"
	@$(CC) $(CFLAGS) $< -o $@ -L. -l:$(LIBFT_FILE)

server_bonus:	$(C_BSRV) $(LIBFT_FILE)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<	->	$@"
	@$(CC) $(CFLAGS) $< -o $@ -L. -l:$(LIBFT_FILE)

client_bonus:	$(C_BCLN) $(LIBFT_FILE)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<	->	$@"
	@$(CC) $(CFLAGS) $< -o $@ -L. -l:$(LIBFT_FILE)

$(LIBFT_FILE):
	@make -C "libft" added

# --------------------------------------

clean:
	clear
	@make -C "libft" clean

fclean:
	@make -C "libft" fclean
	@rm -rf server client server_bonus client_bonus 2>/dev/null ; true

re:	fclean all

bonus: server_bonus client_bonus

# --------------------------------------

norm:
	@norminette -R CheckForbiddenSourceHeader *.c *.h 2>/dev/null ; true

leaks:	CFLAGS += -g3 -fsanitize=address

.PHONY: all, clean, fclean, re, bonus, norm, leaks
