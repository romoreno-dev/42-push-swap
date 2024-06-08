# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 23:55:27 by romoreno          #+#    #+#              #
#    Updated: 2023/10/29 23:55:27 by romoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME 				:= push_swap
COMPILER 			:= gcc -Wall -Wextra -Werror
REMOVER 			:= rm -rf

LIBFT_ROUTE 		:= include/libft
SRC 				:= src
SRC_BONUS			:= src_bonus
OBJ					:= obj/obj
OBJ_BONUS			:= obj/obj_bonus/

CHECKING 			:= checking
DATA_STRUCTURE 		:= data_structure
MOVEMENTS 			:= movements
MOVEMENTS_IMPL 		:= $(MOVEMENTS)/movements_implementation
SORTING 			:= sorting
SORTING_IMPL 		:= $(SORTING)/sorting_implementation
UTILS 				:= utils

SRC_FILES 			:= $(SRC)/main.c \
				$(SRC)/$(CHECKING)/checking.c \
				$(SRC)/$(DATA_STRUCTURE)/stack_init.c \
				$(SRC)/$(DATA_STRUCTURE)/stack_functions.c \
				$(SRC)/$(MOVEMENTS)/movements.c \
				$(SRC)/$(MOVEMENTS)/movements_reverse_rotate.c \
				$(SRC)/$(MOVEMENTS)/movements_reverse.c \
				$(SRC)/$(MOVEMENTS_IMPL)/push_implementation.c \
				$(SRC)/$(MOVEMENTS_IMPL)/reverse_rotate_implementation.c \
				$(SRC)/$(MOVEMENTS_IMPL)/rotate_implementation.c \
				$(SRC)/$(MOVEMENTS_IMPL)/swap_implementation.c \
				$(SRC)/$(SORTING)/sorting.c \
				$(SRC)/$(SORTING_IMPL)/algorithm_to_a_implementation.c \
				$(SRC)/$(SORTING_IMPL)/algorithm_to_b_implementation.c \
				$(SRC)/$(SORTING_IMPL)/algorithm_utils.c \
				$(SRC)/$(UTILS)/cleaning_utils.c \
				$(SRC)/$(UTILS)/number_utils.c \
				$(SRC)/$(UTILS)/printing_utils.c

SRC_BONUS_FILES := $(SRC_BONUS)/main_bonus.c \
				$(SRC_BONUS)/$(CHECKING)/checking_bonus.c \
				$(SRC_BONUS)/$(DATA_STRUCTURE)/stack_init_bonus.c \
				$(SRC_BONUS)/$(DATA_STRUCTURE)/stack_functions_bonus.c \
				$(SRC_BONUS)/$(MOVEMENTS_IMPL)/push_implementation_bonus.c \
				$(SRC_BONUS)/$(MOVEMENTS_IMPL)/reverse_rotate_implementation_bonus.c \
				$(SRC_BONUS)/$(MOVEMENTS_IMPL)/rotate_implementation_bonus.c \
				$(SRC_BONUS)/$(MOVEMENTS_IMPL)/swap_implementation_bonus.c \
				$(SRC_BONUS)/$(UTILS)/cleaning_utils_bonus.c \
				$(SRC_BONUS)/$(UTILS)/number_utils_bonus.c \
				$(SRC_BONUS)/$(UTILS)/printing_utils_bonus.c

OBJ_FILES 		:= $(SRC_FILES:.c=.o)
OBJ_BONUS_FILES	:= $(SRC_BONUS_FILES:.c=.o)

LIBFT 			:= $(LIBFT_ROUTE)/libft.a

.c.o:
		@$(COMPILER) -c $< -o ${<:.c=.o}

# Styles
PRINT_TEXT			:= \033[0m
BOLD 				:= \033[1m
GREEN				:= \033[0;32m
BLUE				:= \033[0;94m

# Rules
all: push_swap

$(NAME): $(OBJ_FILES) $(LIBFT)
		@echo "Compiling push_swap..."
		@$(COMPILER) $(OBJ_FILES) $(LIBFT) -o $(NAME)
		@echo "$(GREEN)$(BOLD)push_swap compiled!$(PRINT_TEXT)"

checker: $(OBJ_BONUS_FILES) $(LIBFT)
		@echo "Compiling checker..."
		@$(COMPILER) $(OBJ_BONUS_FILES) $(LIBFT) -o checker
		@echo "$(GREEN)$(BOLD)checker compiled!$(PRINT_TEXT)"

bonus: checker

$(LIBFT):
		@make -C $(LIBFT_ROUTE)

clean:
		@echo "Cleaning..."
		@$(REMOVER) $(OBJ_FILES)
		@$(REMOVER) $(OBJ_BONUS_FILES)
		@echo "$(BLUE)All objects files were cleaned!$(PRINT_TEXT)"

fclean: clean
		@$(REMOVER) $(NAME) checker
		@make fclean -s -C $(LIBFT_ROUTE)
		@echo "$(BLUE)All compiled files were cleaned!$(PRINT_TEXT)"

re: 	fclean all

see:	all
		python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re bonus see
