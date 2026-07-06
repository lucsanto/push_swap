NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = libs/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCS = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

SRCS = src/main.c \
	src/data/data_utils.c \
	src/parser/parser.c \
	src/options/options.c \
	src/stack/stack_utils.c \
	src/stack/stack_utils_extra.c \
	src/stack/stack_index.c \
	src/stack/stack_operations.c \
	src/operations/op_swap.c \
	src/operations/op_push.c \
	src/operations/op_rotate.c \
	src/operations/op_reverse.c \
	src/operations/op_output.c \
	src/operations/op_output_utils.c \
	src/operations/op_output_count.c \
	src/sort/sort_stack.c \
	src/sort/sort_small.c \
	src/sort/simple_sort_utils.c \
	src/sort/simple_sort.c \
	src/sort/medium_sort.c \
	src/sort/medium_sort_utils.c \
	src/sort/complex_sort.c \
	src/sort/complex_restore.c \
	src/strategy/strategy.c \
	src/strategy/disorder.c \
	src/benchmark/benchmark.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft printf