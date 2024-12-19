# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 15:37:19 by kadferna          #+#    #+#              #
#    Updated: 2024/12/18 15:37:23 by kadferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_atoi.c  ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fPIC

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

so: ${OBJS}
	${CC} -shared -o libft.so ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} libft.so

re: fclean all

.PHONY: all clean fclean re so
