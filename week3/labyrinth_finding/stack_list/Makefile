CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = ../linked_list
NAME = stack_list
MAKE = make
LIST_NAME = list.a
LIST_DIR = ../linked_list
SRCS = stack_list.c \
		stack_list_main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIST_DIR)/
	cp $(LIST_DIR)/$(LIST_NAME) $(LIST_NAME)
	$(CC) $(CFLAGS) -I$(INC) -o $(NAME) $(OBJS) $(LIST_NAME)

clean:
	@$(MAKE) clean -C $(LIST_DIR)/
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIST_DIR)/
	@rm -f $(NAME) $(LIST_NAME)

re: fclean all

.PHONY: all clean fclean re