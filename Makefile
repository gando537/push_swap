# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 16:15:24 by mdiallo           #+#    #+#              #
#    Updated: 2021/06/29 20:05:45 by mdiallo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = checker

NAME2 = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC_PATH = src


SRC_NAME = other.c checker.c swap_ch.c swap_rch.c swap_rrch.c\
		push_ch.c gnl.c init_cmd.c execute.c init_pa.c swap_ps.c\
		utils.c check_error.c find.c init_stack.c push_ps.c free_mem.c\
		loop_ps.c swap_rps.c correct_spot.c lst_three.c create_stack.c\
		swap_rrps.c median.c lst_15.c

SRC_NAME2 = init_pa.c swap_ps.c utils.c check_error.c find.c init_stack.c\
			push_ps.c free_mem.c loop_ps.c swap_rps.c correct_spot.c lst_three.c\
			sort.c create_stack.c swap_rrps.c other.c median.c lst_15.c

AR = ar rc

CPPFLAGS = -I include

OBJ_PATH = obj

OBJ_PATH2 = obj2

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_NAME2 = $(SRC_NAME2:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC2 = $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Executable "$(NAME)" made"

$(NAME2): $(OBJ2)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Executable "$(NAME2)" made"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH2)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH2) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ) $(OBJ2)
	@rm -rf $(OBJ_PATH) || true
	@rm -rf $(OBJ_PATH2) || true
	@echo "$(OBJ_PATH) et "$(OBJ_PATH2)" supprimé !"

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@echo "Executable de "$(NAME)" et "$(NAME2)" supprimé !"

re: fclean all
	@echo "Make re done !"
