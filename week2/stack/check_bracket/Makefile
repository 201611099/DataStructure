CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = a.out
MAKE = make
LIST_DIR = ../stack_list
LIST_NAME = list.a
SRCS = check_bracket.c \
		check_bracket_main.c \
		$(LIST_DIR)/stack_list.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIST_DIR)/
	cp $(LIST_DIR)/$(LIST_NAME) $(LIST_NAME)
	$(CC) $(CFLAGS) -I$(LIST_DIR) -o $(NAME) $(OBJS) $(LIST_NAME)

clean:
	@$(MAKE) clean -C $(LIST_DIR)/
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIST_DIR)/
	@rm -f $(NAME) $(LIST_NAME)

re: fclean all

.PHONY: all clean fclean re