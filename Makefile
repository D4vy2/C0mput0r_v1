# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dea <dea@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/08 11:00:17 by dea               #+#    #+#              #
#    Updated: 2015/07/27 11:07:20 by dea              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor_v1

CC = gcc
SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/

SRC = calcul.c main.c error.c error_2.c error_3.c examine_str.c \
	  init.c polynomial.c delta.c \
	  resolve.c rewrite.c sort_tab.c tab_to_string.c

LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

DEL = rm -rf

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "compiling $<"
	@mkdir -p $(@D)
	@$(CC) $(FLAG) -o $@ -c $<

$(NAME): $(OBJ)
	@(cd $(LIBFT_DIR) && $(MAKE))
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo
	@echo " --> $(NAME) created."
	@echo

clean:
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@$(DEL) $(OBJ)
	@echo 
	@echo " clean -> .o deleted."
	@echo 

fclean: clean
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@$(DEL) $(OBJ) $(NAME)
	@echo
	@echo " --> $(NAME) deleted."
	@echo

re: fclean all
	@echo
	@echo "re -> $(NAME) reloaded."
	@echo

.PHONY: clean fclean all re
