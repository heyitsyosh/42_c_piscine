CC = gcc
NAME = bsq
SRCS = srcs/main.c srcs/dynamic_programming.c srcs/tosave.c
OBJS = $(SRCS:.c=.o)
CPPFLAGS = -I includes
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME):
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS) -o $@
