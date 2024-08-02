# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csubires <csubires@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:48:18 by csubires          #+#    #+#              #
#    Updated: 2024/07/25 07:50:18 by csubires         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = render.c	\
		map.c	\
		parse.c	\
		utils.c

C_BONUS = color_bonus.c	\
 		color_utils_bonus.c	\
		render_bonus.c	\
		render_utils_bonus.c	\
		keys_bonus.c	\
		map_bonus.c	\
		parse_bonus.c	\
		utils_bonus.c

MLX_FILE	= minilibx-linux/libmlx_Linux.a
LIBFT_FILE	= libft/libft.a

NAME		= fdf
NAME_C		= $(C_DIR)/main.c
NAME_BONUS	= fdf_bonus
NAME_BC		= $(C_DIR_BONUS)/main_bonus.c
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
CFLAGS_B	= -Wall -Werror -Wextra
O_DIR		= obj
C_DIR		= source
C_DIR_BONUS	= bonus
O_FILES		= $(addprefix $(O_DIR)/,$(C_FILES:%.c=%.o))
O_BONUS		= $(addprefix $(O_DIR)/,$(C_BONUS:%.c=%.o))
PRINT		= echo
GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
ENDC		= \033[0m
MAKEFLAGS	+= --no-print-directory

CFLAGS 		+= -D WIN_W=1920 -D WIN_H=1080 -g
CFLAGS 		+= -I ./minilibx-linux -I ./libft -I ./include -I ./source
CFLAGS_B 	+= -D WIN_W=1920 -D WIN_H=1080 -g
CFLAGS_B	+= -I ./minilibx-linux -I ./libft -I ./include -I ./source
MLXFLAGS	= -lXext -lX11 -lm -lz

# --------------------------------------

all:	$(NAME)

$(NAME):	$(NAME_C) $(O_FILES) $(LIBFT_FILE) $(MLX_FILE)
	@$(PRINT) "$(GREEN)EXECUTABLE:$(ENDC)	$@"
	@$(CC) $(NAME_C) $(O_FILES) -o $@ -L. -l:$(LIBFT_FILE) -l:$(MLX_FILE) $(CFLAGS) $(MLXFLAGS)

$(O_DIR)/%.o:	$(C_DIR)/%.c $(LIBFT_FILE) | $(O_DIR)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<		->	$@"
	@$(CC) -c $< -o $@ -L ./$(LIBFT_FILE) $(CFLAGS)

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(NAME_BC) $(O_BONUS) $(LIBFT_FILE) $(MLX_FILE)
	@$(PRINT) "$(GREEN)EXECUTABLE:$(ENDC)	$@"
	@$(CC) $(NAME_BC) $(O_BONUS) -o $@ -L. -l:$(LIBFT_FILE) -l:$(MLX_FILE) $(CFLAGS_B) $(MLXFLAGS)

$(O_DIR)/%.o:	$(C_DIR_BONUS)/%.c $(LIBFT_FILE) | $(O_DIR)
	@$(PRINT) "$(GREEN)OBJECT:$(ENDC)\t$<		->	$@"
	@$(CC) -c $< -o $@ -L ./$(LIBFT_FILE) $(CFLAGS_B)

$(LIBFT_FILE):
	@make -C "libft" added

$(MLX_FILE):
	@make -C "minilibx-linux" 2>/dev/null ; true

$(O_DIR):
	@mkdir -p $(O_DIR)

# --------------------------------------

clean:
	clear
	@$(PRINT) "$(RED)REMOVED!: OBJECTS$(ENDC)"
	@make -C "libft" clean
	@make -C "minilibx-linux" clean
	@rm -fr -v $(O_DIR) *.o 2>/dev/null ; true

fclean: clean
	@$(PRINT) "$(RED), LIBRARY, EXECUTABLE$(ENDC)"
	@make -C "libft" fclean
	@rm -rf -v $(NAME) $(NAME_BONUS) 2>/dev/null ; true

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
