CC = gcc

SRCS = events.c check_maps.c parsing_map.c map_validation.c  main.c
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
	MLX_FLAGS =  -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS =  -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

TARGET = so_long

all: $(LIBRARY_PATH) $(TARGET) 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(LIBRARY_PATH):
	@make -C $(MLX_LIB)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CUSTOM_LIBS) $(MLX_LIB) $(MLX_FLAGS) -o $(TARGET) $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re