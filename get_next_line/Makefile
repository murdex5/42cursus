CC = gcc 
FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=n
NAME = libline.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $<

all : $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re