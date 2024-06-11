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

NAME_S = server
NAME_C = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_S = ./src/server.c ./src/server_utils.c
SRCS_C = ./src/client.c
SRCS_U = ./src/utils.c
HEADERS = ./include/minitalk.h
DPRINTF = ./ft_printf
PRTF = $(DPRINTF)/printf.a

OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)
OBJS_U = $(SRCS_U:.c=.o)

all : $(NAME_C) $(NAME_S)

$(NAME_S) : $(OBJS_S) $(OBJS_U) $(PRTF)
	@$(CC) $^ $(CFLAGS) $(PRTF) -o $(NAME_S)

$(NAME_C) : $(OBJS_C) $(OBJS_U) $(PRTF)
	$(CC) $^ $(CFLAGS) $(PRTF) -o $(NAME_C)

$(PRTF) : FORCE
	@$(MAKE) --no-print-directory -C$(DPRINTF)

%.o:%.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	cd $(DPRINTF) && make clean
	rm -rf $(OBJS_C)
	rm -rf $(OBJS_S)
	rm -rf $(OBJS_U)

fclean : clean
	cd $(DPRINTF) && make fclean
	rm -rf $(NAME_S)
	rm -rf $(NAME_C)

re : fclean all

FORCE:

.PHONY : all clean fclean re FORCE