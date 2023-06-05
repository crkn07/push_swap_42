# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 16:47:39 by crtorres          #+#    #+#              #
#    Updated: 2023/05/26 16:48:04 by crtorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

BONUS = checker

SRC_PATH = ./src

INC = ./includes/

DOT_O = _objFiles
DOT_O2 = _objFiles2/

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -I inc -I libft -Wall -Wextra -Werror

SRC = push_swap.c list_stack_utils.c list_stack_utils2.c free_and_exit.c \
		check_is_sorted.c movements.c movements2.c sort_quicksort.c \
		checkindex_instack.c rotate_and_push_stacks.c what_stack_rotate.c \
		times_types_rotations.c main.c\

BONUS_SRC = push_swap.c list_stack_utils.c list_stack_utils2.c free_and_exit.c \
		check_is_sorted.c movements.c movements2.c sort_quicksort.c \
		checkindex_instack.c rotate_and_push_stacks.c what_stack_rotate.c \
		times_types_rotations.c checker.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJS = $(addprefix $(DOT_O)/, $(SRC:%.c=%.o))

SRCS_BONUS = $(addprefix $(SRC_PATH), $(BONUS_SRC))

OBJS_B = $(addprefix $(DOT_O2)/, $(BONUS_SRC:%.c=%.o))

all: make_lib $(NAME) $(DOT_O)

bonus: make_lib $(BONUS)

make_lib:
	@make -sC ./libft

$(NAME): $(OBJS)
	$(PURPLE) COMPILING LIBFT... $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	$(GREEN) "\n👍🏽push_swap succesfully compiled!👍🏽\n " $(RESET)

$(BONUS): $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o $(BONUS)
	$(PURPLE) BONUS COMPILED $(RESET)

$(DOT_O):
	@mkdir -p $(DOT_O)
$(DOT_O2):
	@mkdir -p $(DOT_O2)

$(DOT_O)/%.o: $(SRC_PATH)/%.c | $(DOT_O)
	$(PURPLE) COMPILING PUSH_SWAP... $(RESET)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(DOT_O2)/%.o: $(SRC_PATH)/%.c | $(DOT_O2)
	$(PURPLE) COMPILING BONUS... $(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(PURPLE) "\n" CLEANING... $(RESET)
	@rm -f $(OBJS)
	@rm -rf $(DOT_O)
	@rm -rf $(DOT_O2)
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	$(PURPLE) CLEANING libft... $(RESET)
	@make fclean -C ./libft
	$(GREEN) "CLEAN COMPLETE\n" $(RESET)

fclean: clean

re: fclean
	@make -s all

# COLORS #
#
GREEN 	= @echo "\033[0;32m"
BLUE 	= @echo "\033[0;34m"
PURPLE 	= @echo "\033[0;35m"
CYAN 	= @echo "\033[0;36m"
YELLOW = \033[0;93m
RESET 	= "\033[1;0m"

.PHONY: all clean fclean re