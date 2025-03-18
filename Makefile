NAME = pushswap

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRCS = main.c validate_input.c small_sort.c big_sort.c \
		utils/ft_atol.c utils/helper_functions.c utils/linked_list_funcs.c \
		operations/push_swap_ops.c operations/rotate.c operations/rev_rotate.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCLUDES = -I$(LIBFT_DIR) -Iutils/
LIBS = -L$(LIBFT_DIR) -lft

all: $(NAME)

libs:
	@make -C $(LIBFT_DIR)

$(NAME): libs $(UTILS) $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libs
