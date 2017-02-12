# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 00:55:05 by yarypert          #+#    #+#              #
#    Updated: 2017/02/02 06:10:04 by yarypert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG = -Wall -Wextra -Werror -gdb

SRC_PATH = ./SRC/

INC_PATH = ./Includes/

SRC = $(SRC_PATH)main.c $(SRC_PATH)parse.c $(SRC_PATH)add_to_tab.c $(SRC_PATH)create_grid.c $(SRC_PATH)ft_fillit.c $(SRC_PATH)replace_char.c $(SRC_PATH)ft_error.c $(SRC_PATH)get_coord.c

OBJ = main.o parse.o add_to_tab.o create_grid.o ft_fillit.o replace_char.o ft_error.o get_coord.o

Std = \0033[48;5;236m
Blk = \0033[48;5;16m
Wht = \0033[48;5;15m
Wht2 = \033[38;5;15m
Red = \0033[48;5;124m
Grn = \0033[48;5;34m
Grn2 = \033[38;5;40m
Blu = \0033[48;5;19m
Pnk = \0033[48;5;175m
Bwn = \0033[48;5;233m
Bwn2 = \0033[48;5;130m
Gry = \0033[48;5;245m
Gry2 = \0033[48;5;72m
Skn = \0033[48;5;216m

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) -I $(INC_PATH)
	@gcc $(OBJ) ./libft/libft.a -I $(INC_PATH) -o $(NAME)
	@mkdir tmp
	@mv $(OBJ) tmp
	

.PHONY: clean
clean :
	@rm -Rf tmp
	@echo "$(Grn2)[✓] $(Wht2) Removed OBJ tmp file" $(NAME)


fclean: clean
	@rm -Rf $(NAME)
	@echo "$(Grn2)[✓] $(Wht2) Removed executable" $(NAME)

re : fclean all
