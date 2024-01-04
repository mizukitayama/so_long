CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rcs

SRCS	=	ft_printf.c ft_printf_utils.c ft_putpnt.c ft_putuint.c ft_puthex.c
LIBFT	=	libft/

NAME	=	libftprintf.a

OBJ_DIR	=	obj/
SRC_DIR	=	src/

SRCS_OBJS	=	$(SRCS:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(SRCS_OBJS))

INCLUDE	=	-I libft/ -I inc/

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp $(LIBFT)libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

clean:
	make clean -C libft
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re:	fclean $(NAME)
	make re -C libft