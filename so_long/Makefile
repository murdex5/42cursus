CC = gcc

SRCS = so_long.c events.c check_maps.c parsing_map.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I. -Imlx

CUSTOM_LIBS = my_libs/libft.a

LIBRARY_PATH = minlibx-linux
MLX_LIB = -L$(LIBRARY_PATH) -lmlx

MLX_FLAGS = -lX11 -lXext -lm -lz

TARGET = so_long

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CUSTOM_LIBS) $(MLX_LIB) $(MLX_FLAGS) -o $(TARGET)

all: $(TARGET)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re