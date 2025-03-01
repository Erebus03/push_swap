#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	
}	t_stack;

/* validate_input.c */
char	**validate_input(int ac, char **av);
int		convert_check_args(int j, char ***args);
int		is_integer(char *s);
void	free_args(int ac, char ***args);



char **ft_split(const char *s, char c);
#endif