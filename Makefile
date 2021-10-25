NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
HEADER = push_swap.h
SRCS = srcs/ft_atoi.c\
			 srcs/ft_isdigit.c\
			 srcs/ft_memset.c\
			 srcs/ft_bzero.c\
			 srcs/swap.c\
			 srcs/push.c\
			srcs/rotate.c\
			srcs/reverce_rotate.c\
			srcs/utils1.c\
			srcs/utils2.c\
			srcs/utils3.c\
			srcs/rule_sort.c\
			srcs/num3_sort.c\
			srcs/quick_sort.c\
			srcs/six_len_sort.c\
			srcs/operation.c\
			srcs/error_check.c\
			srcs/free.c\
			srcs/main.c

OBJS = $(SRCS:c=o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o push_swap $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


