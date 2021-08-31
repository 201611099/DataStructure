CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=db_list.a
INC=./utils/
SRCS = double_linked_list.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
