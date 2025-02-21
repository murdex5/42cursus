CC = gcc

SRCS = main.c events.c check_maps.c parsing_map.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I. -Imlx

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

CUSTOM_LIBS = my_libs/libft.a

LIBRARY_PATH = ./mlx
MLX_LIB = -L$(LIBRARY_PATH) -lmlx

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

TARGET = so_long

all: $(TARGET) $(LIBRARY_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CUSTOM_LIBS) $(MLX_LIB) $(MLX_FLAGS) -o $(TARGET) $(INCLUDES)

$(LIBRARY_PATH):
	@make -C $(LIBRARY_PATH)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re