# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minakim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 17:25:20 by minakim           #+#    #+#              #
#    Updated: 2019/06/25 23:09:30 by minakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

OPTION = -I$(HEADER) -c
FLAG = -Wall -Wextra -Werror

SRC = \
ft_atoi.c\
ft_bzero.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_itoa_base.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_strupper.c\
ft_tolower.c\
ft_toupper.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstnew.c\
ft_lstmap.c\
ft_nbrlen.c\
ft_binary.c\
ft_strrev.c\
ft_swap.c\
ft_wstrlen.c\
ft_strjoin_mod.c\
ft_count_words.c\
ft_count_letters.c\
check.c\
ft_printf.c\
initiation.c\
print_format.c\
specifier1.c\
specifier2.c\
specifier3.c\
trim.c\
get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc $(FLAG) $(SRC) $(OPTION)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
