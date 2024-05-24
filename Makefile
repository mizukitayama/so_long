CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -L /usr/X11/lib
LDLIBS  = -lX11 -lXext -framework OpenGL -framework AppKit

RM      = rm -rf

SRCS    = so_long.c parse_input.c utils.c map.c move.c exit_process.c \
					check_valid_path.c key_hooks.c init_images.c animation.c enemy.c \
					move_count.c

GET_NEXT_LINE_DIR = get_next_line/
GET_NEXT_LINE = get_next_line.a

PRINTF_DIR = printf/
PRINTF = libftprintf.a

LIBFT_DIR = printf/libft/
LIBFT = libft.a

MLX_DIR = minilibx-linux/
LIBMLX = libmlx.a

NAME    = so_long

OBJ_DIR = obj/
SRC_DIR = src/

SRCS_OBJS = $(SRCS:.c=.o)
OBJS      = $(addprefix $(OBJ_DIR), $(SRCS_OBJS))

INCLUDE = -I $(GET_NEXT_LINE_DIR) -I $(PRINTF_DIR) -I $(MLX_DIR) -I inc/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(GET_NEXT_LINE_DIR)
	make -C $(PRINTF_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LDFLAGS) $(LDLIBS) $(GET_NEXT_LINE_DIR)$(GET_NEXT_LINE) $(PRINTF_DIR)$(PRINTF) $(MLX_DIR)$(LIBMLX)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

clean:
	make clean -C $(GET_NEXT_LINE_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(GET_NEXT_LINE_DIR)$(GET_NEXT_LINE)
	$(RM) $(PRINTF_DIR)$(PRINTF)
	$(RM) $(LIBFT_DIR)$(LIBFT)
	$(RM) $(MLX_DIR)$(LIBMLX)

re: fclean $(NAME)
	make re -C $(GET_NEXT_LINE_DIR)
	make re -C $(PRINTF_DIR)
	make re -C $(MLX_DIR)
