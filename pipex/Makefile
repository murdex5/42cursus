CC = gcc
SRCS = 
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Werror -Wextra
LIBFT_PATH = ./libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
NAME = pipex


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