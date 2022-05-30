# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 23:28:54 by chtang            #+#    #+#              #
#    Updated: 2022/02/27 23:34:31 by chtang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := rush-02
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS = algo.c algo_sub.c dict_check.c dict_read.c main.c sub_function.c sub_function_2.c
OBJS := $(SRCS:%.c=%.o)
DEPS := $(SRCS:%.c=%.d)
RM := rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all
all: $(NAME)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c -MMD -MP $<

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

re: fclean all
