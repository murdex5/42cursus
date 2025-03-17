# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 10:05:06 by kadferna          #+#    #+#              #
#    Updated: 2025/03/17 10:45:26 by kadferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = utils0.c \
		swap_func.c \
		main.c
FLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
NAME = push_swap

all: subsystems $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

subsystems:
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re subsytems
