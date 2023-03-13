NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT = ./libft/libft.a
# BONUSLIB = ./bonus/libbonus.a

SRCS = push_swap.c \
	stack_utils.c \
	sort.c \
	radix.c \
	check_arg.c \
	set_stack.c \
	movements.c

OBJS = $(SRCS:%.c=%.o)

# BONUS_SRCS = 

# BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all: libft $(NAME)

libft:
	make -C ./libft

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT) -o $(NAME)

# bonus: libft $(BONUSLIB)

# $(BONUSLIB): $(BONUS_OBJS) $(LIBFT)
# 	ar rcs $(BONUSLIB) $(BONUS_OBJS)
# 	cc $(BONUSLIB) $(LIBFT) -o $(NAME)

clean:
	make clean -C ./libft 
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

# rebonus: fclean bonus

.PHONY: all clean fclean re libft