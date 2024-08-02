# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csubires <csubires@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:48:18 by csubires          #+#    #+#              #
#    Updated: 2024/07/25 07:51:07 by csubires         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = ft_parse.c \
		ft_rotate.c \
		ft_calculate.c \
		ft_sort.c

C_BONUS = checker_bonus.c

STACK_FILE	= stack/stack.a
LIBFT_FILE	= libft/libft.a

NAME		= push_swap
NAME_C		= $(C_DIR)/$(NAME).c
NAME_BONUS	= checker
NAME_BC		= $(C_DIR_BONUS)/$(C_BONUS)
CC			= clang
AR			= ar -crs
CFLAGS		= -Wall -Werror -Wextra -gdwarf-4 -I $(H_FILES)
H_FILES		= ./source
O_DIR		= obj
C_DIR		= source
C_DIR_BONUS	= bonus
O_FILES		= $(addprefix $(O_DIR)/,$(C_FILES:%.c=%.o))
PRINT		= echo
GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
ENDC		= \033[0m
MAKEFLAGS	+= --no-print-directory

# --------------------------------------

all:	$(NAME)

$(NAME):	$(NAME_C) $(O_FILES) $(LIBFT_FILE) $(STACK_FILE)
	@$(PRINT) "$(GREEN)EXECUTABLE:$(ENDC)	$@"
	@$(CC) $(CFLAGS) $(NAME_C) $(O_FILES) -L. -l:$(LIBFT_FILE) -l:$(STACK_FILE) -o $@

$(O_DIR)/%.o:	$(C_DIR)/%.c | $(O_DIR)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<		->	$@"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(NAME_BC) $(O_FILES) $(LIBFT_FILE) $(STACK_FILE)
	@$(PRINT) "$(GREEN)EXECUTABLE:$(ENDC)	$@"
	@$(CC) $(CFLAGS) $(NAME_BC) $(O_FILES) -L. -l:$(LIBFT_FILE) -l:$(STACK_FILE) -o $@

$(LIBFT_FILE):
	@make -C "libft" added

$(STACK_FILE):
	@make -C "stack"

$(O_DIR):
	@mkdir -p $(O_DIR)

# --------------------------------------

clean:
	clear
	@$(PRINT) "$(RED)REMOVED!: OBJECTS$(ENDC)"
	@make -C "libft" clean
	@rm -fr -v $(O_DIR) $(O_DIR_BONUS) *.o 2>/dev/null ; true

fclean: clean
	@$(PRINT) "$(RED), LIBRARY, EXECUTABLE$(ENDC)"
	@make -C "libft" fclean
	@rm -rf -v $(NAME) $(NAME_BONUS) $(NAME_CHECK) $(STACK_FILE) 2>/dev/null ; true

re:	fclean all

# --------------------------------------

print:
		@$(PRINT) "$(YELLOW)NAME LIBRARY:$(ENDC)\t$(NAME)"
		@$(PRINT) "$(YELLOW)SOURCES:$(ENDC)\t$(C_FILES)"
		@$(PRINT) "$(YELLOW)OBJECTS:$(ENDC)\t$(O_FILES)"
		@nm --print-armap $(NAME) 2>/dev/null ; true

norm:
	@norminette -R CheckForbiddenSourceHeader **/*.c **/*.h 2>/dev/null ; true

leaks:	CFLAGS += -g -fsanitize=address

.PHONY: all, clean, fclean, re, bonus, added, print, norm, leaks
