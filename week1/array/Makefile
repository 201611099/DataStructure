CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=arr
INC=./utils/
SRCS = array.c \
		main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
