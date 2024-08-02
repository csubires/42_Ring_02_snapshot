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

C_FILES	= get_next_line.c
C_BONUS = get_next_line_bonus.c

LIBFT_FILE	= libft/libft.a

NAME		= tester
NAME_C		= main.c
HEADER		= get_next_line.h
HEADER_B	= get_next_line_bonus.h
CC			= clang
AR			= ar -crs
BUFFER_SIZE	= 100
CFLAGS 		= -D BUFFER_SIZE=$(BUFFER_SIZE) -Wall -Werror -Wextra -I$(H_FILES)
H_FILES		= .
O_DIR		= obj
O_DIR_BONUS = obj
C_DIR		= .
O_FILES		= $(addprefix $(O_DIR)/,$(C_FILES:%.c=%.o))
O_BONUS		= $(addprefix $(O_DIR)/,$(C_BONUS:%.c=%.o))
PRINT		= echo
GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
ENDC		= \033[0m
MAKEFLAGS	+= --no-print-directory

# --------------------------------------

all:	$(NAME)

$(NAME):	$(NAME_C) $(O_FILES) $(LIBFT_FILE)
	@$(PRINT) "$(GREEN)EXECUTABLE:$(ENDC)	$@"
	@$(CC) $(CFLAGS) $(NAME_C) $(O_FILES) -L. -l:$(LIBFT_FILE) -o $@

$(O_DIR)/%.o:	$(C_DIR)/%.c | $(O_DIR)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<		->	$@"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(NAME_C) $(O_BONUS) $(LIBFT_FILE)
	@$(PRINT) "$(GREEN)EXECUTABLE:$(ENDC)	$@"
	@$(CC) $(CFLAGS) $(NAME_C) $(O_BONUS) -L. -l:$(LIBFT_FILE) -o tester_bonus

$(O_DIR)/%.o:	$(C_DIR)/%.c | $(O_DIR)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<		->	$@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_FILE):
	@make -C "libft"

$(O_DIR):
	@mkdir -p $(O_DIR)

# --------------------------------------

clean:
	clear
	@$(PRINT) "$(RED)REMOVED!: OBJECTS$(ENDC)"
	@make -C "libft" clean
	@rm -fr -v $(O_DIR) $(O_DIR_BONUS) *.o 2>/dev/null ; true

fclean:	clean
	@$(PRINT) "$(RED), LIBRARY, EXECUTABLE$(ENDC)"
	@make -C "libft" fclean
	@rm -rf -v $(NAME) $(LIBFT_FILE) 2>/dev/null ; true

re:	fclean all

# --------------------------------------

print:
		@$(PRINT) "\n$(YELLOW)NAME LIBRARY$(ENDC):\n\t$(NAME)\n"
		@$(PRINT) "\n$(YELLOW)SOURCES$(ENDC):\n\t$(C_FILES)\n"
		@$(PRINT) "\n$(YELLOW)OBJECTS$(ENDC):\n\t$(O_FILES)\n\n"
		@$(PRINT) "\n$(YELLOW)SOURCES BONUS$(ENDC):\n\t$(C_BONUS)\n"
		@$(PRINT) "\n$(YELLOW)OBJECTS BONUS$(ENDC):\n\t$(O_BONUS)\n\n"
		@nm --print-armap $(NAME) 2>/dev/null ; true

norm:
		@norminette -R CheckForbiddenSourceHeader $(C_FILES) $(C_BONUS) $(HEADER) $(HEADER_B) 2>/dev/null ; true

leaks:	CFLAGS += -g -fsanitize=address

.PHONY: all, clean, fclean, re, bonus, print, norm, leaks
