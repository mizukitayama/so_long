CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

SRCS	=	ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

NAME	=	libft.a

SRCS_OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	ar rcs $(NAME) $(SRCS_OBJS)

clean:
	$(RM) $(SRCS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)