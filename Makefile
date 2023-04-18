# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 15:30:25 by crtorres          #+#    #+#              #
#    Updated: 2023/04/18 12:54:41 by crtorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRC_PATH = ./src/

INC = ./includes/

DOT_O = _objFiles/

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I inc -I libft

SRC = push_swap.c exit_msg.c list_stack_utils.c list_stack_utils2.c \
		free_and_exit.c check_numbers.c check_is_sorted.c movements.c \
		movements2.c sort_quicksort.c checkindex_instack.c \
		rotate_and_push_stacks.c what_stack_rotate.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJS =  $(addprefix $(DOT_O)/, $(SRC:%.c=%.o))

all: make_lib $(NAME) $(DOT_O)

make_lib:
	@make -sC ./libft

$(DOT_O):
	@mkdir $(DOT_O)
# The -p flag will create nested directories, but only if they don't 
# exist already.

$(DOT_O)/%.o: $(SRC_PATH)/%.c | $(DOT_O)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	$(GREEN) "\n👍🏽push_swap succesfully compiled!👍🏽\n " $(RESET)

clean:
	$(PURPLE) CLEANING... $(RESET)
	@rm -f $(OBJS)
	@rm -rf $(DOT_O)
	$(PURPLE) CLEANING libft... $(RESET)
	@make fclean -C ./libft
	$(GREEN) "CLEAN COMPLETE" $(RESET)

fclean: clean

re: fclean all

# COLORS #
#
GREEN 	= @echo "\033[0;32m"
BLUE 	= @echo "\033[0;34m"
PURPLE 	= @echo "\033[0;35m"
CYAN 	= @echo "\033[0;36m"
RESET 	= "\033[1;0m"

.PHONY: all clean fclean re