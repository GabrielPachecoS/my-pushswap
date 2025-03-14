NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = src/ft_lstsize.c src/ft_lstlast.c src/full_sort.c src/move_utils.c src/populate_stack.c src/prepare_a.c src/prepare_b.c src/push_split.c src/push_swap.c src/push_utils.c src/push.c src/reverse.c src/rotate.c src/small_sort.c src/swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "Push_swap build complete."

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "Libft build complete."

%.o: %.c push_swap.h libft/libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "Clean complete."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "Fclean complete."

re: fclean all

.PHONY: all clean fclean re