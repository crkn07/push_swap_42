# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 15:10:03 by crtorres          #+#    #+#              #
#    Updated: 2023/04/24 16:44:30 by crtorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC_PATH = ./src/

BONUS_PATH = ./checker/

INC = ./includes/

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -I inc -I libft -Wall -Wextra -Werror

SRC = push_swap.c list_stack_utils.c list_stack_utils2.c free_and_exit.c \
		check_is_sorted.c movements.c movements2.c sort_quicksort.c \
		checkindex_instack.c rotate_and_push_stacks.c what_stack_rotate.c \
		times_types_rotations.c \

SRC_MAIN = main.c \

BONUS_SRC = checker.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRC_MN = $(addprefix $(SRC_PATH), $(SRC_MAIN))
SRCS_BONUS = $(addprefix $(BONUS_PATH), $(BONUS_SRC))

OBJS = $(SRCS:%.c=%.o) $(SRC_MN:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(PURPLE) COMPILING LIBFT... $(RESET)
	@make -sC ./libft
	$(PURPLE) COMPILING PUSH_SWAP... $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	$(GREEN) "\n👍🏽push_swap succesfully compiled!👍🏽\n " $(RESET)

$(NAME_BONUS): $(OBJS_BONUS)
	$(PURPLE) COMPILING LIBFT... $(RESET)
	@make -sC ./libft
	$(PURPLE) COMPILING BONUS... $(RESET)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)


clean:
	$(PURPLE) CLEANING... $(RESET)
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
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
RESET 	= "\033[1;0m"

.PHONY: all clean fclean re