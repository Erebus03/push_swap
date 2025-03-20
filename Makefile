NAME = pushswap

SRCS = main.c validate_input.c small_sort.c big_sort.c \
		utils/ft_atol.c utils/ft_split.c utils/helper_functions.c utils/linked_list_funcs.c \
		operations/push_swap_ops.c operations/rotate.c operations/rev_rotate.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCLUDES = -Iutils/

all: $(NAME)

$(NAME): $(UTILS) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re