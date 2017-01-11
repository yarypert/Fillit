# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 00:55:05 by yarypert          #+#    #+#              #
#    Updated: 2017/01/11 14:54:28 by yarypert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG = -Wall -Wextra -Werror

SRC_PATH = ./SRC/

SRC = $(SRC_PATH)main.c $(SRC_PATH)parse.c $(SRC_PATH)libft.a

OBJ = ${SRC:c=o}

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
	@gcc $(FLAG) $(SRC) -o $(NAME)
	@echo "$(Std)                                                            ""$(Std)                                        ""$(Std)                                                     "
	@echo "$(Std)                          $(Blk)                  $(Std)                ""$(Std)                                        ""$(Std)               $(Blk)                  $(Std)      $(Blk)  $(Std)            "
	@echo "$(Std)                        $(Blk)  $(Bwn)                  $(Blk)  $(Std)              ""$(Std)                                        ""$(Std)             $(Blk)  $(Bwn)                  $(Blk)  $(Std)  $(Blk)  $(Gry)  $(Blk)  $(Std)          "
	@echo "$(Std)                      $(Blk)  $(Bwn)                      $(Blk)  $(Std)            ""$(Std)                                        ""$(Std)           $(Blk)  $(Bwn)                      $(Blk)    $(Gry)    $(Blk)  $(Std)        "
	@echo "$(Std)                    $(Blk)  $(Bwn)                          $(Blk)  $(Std)          ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)                          $(Blk)    $(Gry)    $(Blk)  $(Std)      "
	@echo "$(Std)                    $(Blk)  $(Bwn)                          $(Blk)  $(Std)          ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)                          $(Blk)    $(Gry)    $(Blk)  $(Std)      "
	@echo "$(Std)                    $(Blk)  $(Bwn)    $(Skn)      $(Bwn)      $(Skn)      $(Bwn)    $(Blk)  $(Std)          ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)                          $(Blk)    $(Gry)    $(Blk)  $(Std)      "
	@echo "$(Std)                    $(Blk)  $(Bwn)  $(Skn)                      $(Bwn)  $(Blk)  $(Std)          ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)          $(Skn)      $(Bwn)          $(Blk)    $(Red)  $(Gry)    $(Blk)  $(Std)    "
	@echo "$(Std)                    $(Blk)  $(Bwn)  $(Skn)                      $(Bwn)  $(Blk)  $(Std)          ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)      $(Skn)              $(Bwn)      $(Blk)    $(Red)    $(Gry)  $(Blk)  $(Std)    "
	@echo "$(Std)                    $(Blk)  $(Bwn)  $(Std)  $(Gry)    $(Wht)  $(Gry)  $(Std)  $(Gry)    $(Wht)  $(Gry)  $(Std)  $(Bwn)  $(Blk)  $(Std)          ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)    $(Skn)  $(Wht)  $(Gry2)  $(Skn)      $(Gry2)  $(Wht)  $(Skn)  $(Bwn)    $(Blk)    $(Red)    $(Gry)  $(Blk)  $(Std)    "
	@echo "$(Std)                    $(Blk)  $(Skn)    $(Gry)  $(Wht)  $(Gry)    $(Skn)  $(Gry)  $(Wht)  $(Gry)    $(Skn)    $(Blk)  $(Std)          ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)    $(Skn)  $(Wht)  $(Gry2)  $(Skn)      $(Gry2)  $(Wht)  $(Skn)  $(Bwn)    $(Blk)    $(Red)  $(Gry)    $(Blk)  $(Std)    "
	@echo "$(Std)      $(Blk)          $(Std)    $(Blk)  $(Skn)                          $(Blk)  $(Std)          ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)    $(Skn)                  $(Bwn)    $(Blk)    $(Gry)      $(Blk)  $(Std)    "
	@echo "$(Std)    $(Blk)  $(Red)          $(Blk)  $(Std)    $(Blk)  $(Bwn)                      $(Blk)  $(Std)            ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)    $(Skn)                  $(Bwn)    $(Blk)    $(Red)  $(Gry)    $(Blk)  $(Std)    "
	@echo "$(Std)  $(Blk)  $(Gry)  $(Red)      $(Gry)      $(Blk)  $(Std)    $(Blk)    $(Bwn)    $(Skn)      $(Bwn)    $(Blk)    $(Std)              ""$(Std)    $(Grn2)[✓] $(Wht2)Created Fillit executable       ""$(Std)         $(Blk)  $(Bwn)    $(Blk)  $(Skn)              $(Blk)  $(Bwn)    $(Blk)    $(Gry)      $(Blk)  $(Std)    "
	@echo "$(Std)  $(Blk)  $(Gry)    $(Red)    $(Gry)      $(Blk)  $(Std)      $(Blk)                  $(Std)                ""$(Std)                                        ""$(Std)         $(Blk)  $(Bwn)    $(Blk)                  $(Bwn)    $(Blk)    $(Red)  $(Gry)    $(Blk)  $(Std)    "
	@echo "$(Std)    $(Blk)  $(Gry)  $(Red)    $(Gry)    $(Blk)  $(Std)      $(Blk)      $(Grn)    $(Wht)  $(Grn)    $(Blk)      $(Std)              ""$(Std)                                        ""$(Std)           $(Blk)  $(Bwn)  $(Blk)    $(Pnk)  $(Skn)      $(Pnk)  $(Blk)    $(Bwn)  $(Blk)  $(Std)  $(Blk)  $(Gry)      $(Blk)  $(Std)    "
	@echo "$(Std)    $(Blk)  $(Gry)  $(Red)  $(Gry)      $(Blk)  $(Std)      $(Blk)  $(Grn)  $(Blk)  $(Grn)    $(Wht)  $(Grn)    $(Blk)  $(Grn)  $(Blk)  $(Std)              ""$(Std)                                        ""$(Std)             $(Blk)  $(Pnk)  $(Blk)  $(Pnk)    $(Wht)  $(Pnk)    $(Blk)  $(Pnk)  $(Blk)  $(Std)    $(Blk)  $(Gry)      $(Blk)  $(Std)    "
	@echo "$(Std)    $(Blk)    $(Gry)      $(Blk)            $(Skn)  $(Blk)  $(Grn)    $(Wht)  $(Grn)    $(Blk)  $(Skn)  $(Blk)            $(Std)    ""$(Std)                                        ""$(Std)    $(Blk)           $(Pnk)  $(Blk)  $(Pnk)    $(Wht)  $(Pnk)    $(Blk)  $(Pnk)  $(Blk)                $(Std)    "
	@echo "$(Std)  $(Blk)  $(Bwn2)  $(Blk)  $(Gry)      $(Blk)  $(Bwn2)        $(Blk)  $(Skn)  $(Blk)  $(Grn)    $(Wht)  $(Grn)    $(Blk)  $(Skn)  $(Blk)  $(Bwn2)          $(Blk)  $(Std)  ""$(Std)                                        ""$(Std)  $(Blk)  $(Bwn2)         $(Blk)  $(Skn)  $(Blk)  $(Pnk)    $(Wht)  $(Pnk)    $(Blk)  $(Skn)  $(Blk)  $(Bwn2)              $(Blk)  $(Std)  "
	@echo "$(Std)    $(Blk)    $(Gry)      $(Blk)                $(Grn)    $(Wht)  $(Grn)    $(Blk)                $(Std)    ""$(Std)                                        ""$(Std)    $(Blk)               $(Pnk)    $(Wht)  $(Pnk)    $(Blk)                    $(Std)    "
	@echo "$(Std)        $(Blk)  $(Gry)  $(Blk)  $(Std)              $(Blk)  $(Blu)  $(Blk)      $(Blu)  $(Blk)  $(Std)                  ""$(Std)                                        ""$(Std)                 $(Blk)  $(Blu)  $(Blk)      $(Blu)  $(Blk)  $(Std)                      "
	@echo "$(Std)          $(Blk)  $(Std)                $(Blk)  $(Bwn)  $(Blk)  $(Std)  $(Blk)  $(Bwn)  $(Blk)  $(Std)                  ""$(Std)                                        ""$(Std)                 $(Blk)  $(Wht)  $(Blk)  $(Std)  $(Blk)  $(Wht)  $(Blk)  $(Std)                      "
	@echo "$(Std)                            $(Blk)      $(Std)  $(Blk)      $(Std)                  ""$(Std)                                        ""$(Std)                 $(Blk)      $(Std)  $(Blk)      $(Std)                      "
	@echo "$(Std)                                                            ""$(Std)                                        ""$(Std)                                                     "

.PHONY: clean
clean :

fclean: clean
	@rm -Rf $(NAME)
	@echo "$(Grn2)[✓] $(Wht2) Removed executable" $(NAME)

re : fclean all
