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
SRCS_DIR = ./srcs
SRCS = ${SRCS_DIR}/utils0.c \
		${SRCS_DIR}/utils1.c \
		${SRCS_DIR}/free.c \
		${SRCS_DIR}/checks.c \
		${SRCS_DIR}/get_ints.c \
		${SRCS_DIR}/rotate_func.c \
		${SRCS_DIR}/reverse_rotate.c \
		${SRCS_DIR}/push_func.c \
		${SRCS_DIR}/swap_func.c \
		${SRCS_DIR}/nodes.c \
		${SRCS_DIR}/algo/turk_utils3.c\
		${SRCS_DIR}/algo/turk_utils2.c\
		${SRCS_DIR}/algo/turk_utils1.c \
		${SRCS_DIR}/algo/turk_utils.c \
		${SRCS_DIR}/algo/ops.c\
		${SRCS_DIR}/algo/turk.c \
		main.c

CFLAGS = -Wall -Werror -Wextra
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
	rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re subsytems
