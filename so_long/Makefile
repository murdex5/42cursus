CC			= gcc
SRCS		= frees.c map.c player.c utils1.c main.c 
OBJS		= ${SRCS:.c=.o}
CFLAGS		= -Wall -Werror -Wextra
MLX_DIR		= ./mlx
MLX_LIB		= $(MLX_DIR)/libmlx.a
LIBFT_PATH	= ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
NAME	= so_long

ifeq ($(shell uname), Linux)
	MLX_FLAGS =  -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS =  -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_DIR) all
	@make -C $(LIBFT_PATH) all


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS)

fclean: clean
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re subsystems