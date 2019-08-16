# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minakim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 20:32:41 by minakim           #+#    #+#              #
#    Updated: 2019/07/18 20:35:36 by minakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SRC = *.c
OBJ = $(SRC:.c=.o)

OBJ_DIR = obj
LIB_DIR = lib/libft/
SRC_DIR = src

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
LIBS = -L $(LIB_DIR) -lft
#HEADER = -I /includes -I $(LIB_DIR)

all: $(NAME)

$(NAME):
	$(MAKE) $(LIB_DIR)
	$(CC) $(CFLAGS) -I. -I $(LIB_DIR) -c $(SRCS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)
	@echo "File \"push_swap\" created\n"

clean:
	@/bin/rm -f $(NAME)
	@rm -f $(LIB_DIR)/libft.a
	@echo "Object File removed\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIB_DIR)/libft.a
	@rm -rf $(OBJ_DIR)
	@echo "Removed excutable & .o files\n"

re: fclean all

.PHONY: all, clean, fclean, re
.SUFFIXES: .c .o
