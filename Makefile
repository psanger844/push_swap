NAME = push_swap
CC = cc -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror
SRCS = list_checker.c list_func.c push_swap.c \
		reverse_rotate_operators.c rotate_operators.c sort_small.c \
		sort_two_t_five.c swap_push_operations.c \
		a_quicksort_improoved.c \

OBJS = $(SRCS:.c=.o)

SUBDIR = LIBFT

all: $(NAME)

$(NAME) : $(SUBDIR) $(OBJS)
	@$(MAKE) -C $(SUBDIR)
	@$(CC) $(OBJS) -L$(SUBDIR) -lft -o $(NAME)

$(SUBDIR):
	@$(MAKE) -C $(SUBDIR)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(SUBDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(SUBDIR) fclean

re: fclean all
