CC = gcc
CFLAGS = -Wall -Werror -Wextra -I
NAME = libft.a
INCLUDE = include/
C_DIR = srcs/
O_DIR = objs/
LIBFT = $(C_DIR)libft/ft_atol.c
PRINTF = $(C_DIR)printf/ft_printf.c $(C_DIR)printf/ft_printf_nums.c $(C_DIR)printf/ft_printf_chars.c $(C_DIR)printf/ft_printf_aux.c $(C_DIR)printf/ft_printf_chars.c
SRCS = $(LIBFT) $(PRINTF)
OBJS = $(patsubst $(C_DIR)%.c,$(O_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(O_DIR)%.o: $(C_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re