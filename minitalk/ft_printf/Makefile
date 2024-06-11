# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchapard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:50:00 by lchapard          #+#    #+#              #
#    Updated: 2023/11/27 16:52:19 by lchapard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c ft_print_char.c ft_print_string.c ft_print_base.c ft_print_int.c ft_write_nb.c ft_print_pointer.c ft_print_adress.c
HEADERS = ft_printf.h
OBJS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
