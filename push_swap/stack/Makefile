# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csubires <csubires@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:48:18 by csubires          #+#    #+#              #
#    Updated: 2024/07/04 10:23:15 by csubires         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = stack.c \
		movements_01.c \
		movements_02.c \
		movements_03.c \
		utils.c

NAME		= stack.a
CC			= clang
AR			= ar -crs
CFLAGS 		= -Wall -Werror -Wextra -gdwarf-4 -I $(H_FILES)
H_FILES		= .
O_DIR		= ../obj
C_DIR		= .

O_FILES		= $(addprefix $(O_DIR)/,$(C_FILES:%.c=%.o))
PRINT		= echo
GREEN		= \033[0;32m
RED			= \033[1;31m
YELLOW		= \033[1;33m
ENDC		= \033[0m
MAKEFLAGS	+= --no-print-directory

# --------------------------------------

all:		$(NAME)

$(NAME):	$(O_FILES) | $(O_DIR)
	@$(PRINT) "$(YELLOW)BUILDING LIBRARY:$(ENDC)\t$(NAME)"
	@$(AR) $(NAME) $(O_FILES)

$(O_DIR)/%.o:	$(C_DIR)/%.c | $(O_DIR)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<		->	$@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(O_DIR):
	@mkdir -p $(O_DIR)

# --------------------------------------

clean:
	clear
	@$(PRINT) "$(RED)REMOVED! OBJECTS$(ENDC)"
	@rm -fr $(O_DIR) *.o 2>/dev/null ; true

fclean: clean
	@$(PRINT) "$(RED), LIBRARY, EXECUTABLE$(ENDC)"
	@rm -rf $(NAME) 2>/dev/null ; true

re:	fclean all

# --------------------------------------

print:
		@$(PRINT) "$(YELLOW)NAME LIBRARY:$(ENDC)\t$(NAME)"
		@$(PRINT) "$(YELLOW)SOURCES:$(ENDC)\t$(C_FILES)"
		@$(PRINT) "$(YELLOW)OBJECTS:$(ENDC)\t$(O_FILES)"
		@nm --print-armap $(NAME) 2>/dev/null ; true

norm:
		@norminette -R CheckForbiddenSourceHeader $(C_FILES) $(C_BONUS) $(C_UTILS) $(C_ADDED) $(HEADER) 2>/dev/null ; true

leaks:	CFLAGS += -g -fsanitize=address

.PHONY: all, clean, fclean, re, bonus, added, print, norm, leaks
