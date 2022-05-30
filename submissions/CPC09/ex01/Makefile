CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I includes
NAME = libft.a
SCRS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS = $(SRCS:.c=.o)

all:$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME):$(OBJS)
	ar -r $@ $^