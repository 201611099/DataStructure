CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = ../../../week1/arr_mentor
NAME = stack_arr
MAKE = make
ARR_NAME = arr.a
ARR_DIR = ../../../week1/arr_mentor
SRCS = stack_arr.c \
		stack_arr_main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(ARR_DIR)/
	cp $(ARR_DIR)/$(ARR_NAME) $(ARR_NAME)
	$(CC) $(CFLAGS) -I$(INC) -o $(NAME) $(OBJS) $(ARR_NAME)

clean:
	@$(MAKE) clean -C $(ARR_DIR)/
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(ARR_DIR)/
	@rm -f $(NAME) $(ARR_NAME)

re: fclean all

.PHONY: all clean fclean re