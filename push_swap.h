#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "utils/utils.h"
#include "operations/operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct _vars {
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*array;
}	t_vars;

/* validate_input.c */
int		validate_input(int ac, char **av, t_stack **stack_a);
int		fill_nd_check_dup(char **args, t_stack **stack_a);
int		process_arg(char **arg, t_stack **stack_a);
int		is_integer(char *s);

/* main */
void	free_args(char **);

void	bigsort(t_stack **a, t_stack **b, int *array_of_ints, int size);
void	updateindex(int *i, int *j);

void	printf_stacks(t_stack **a, t_stack **b);

void	sort3(t_stack **a);
void	sort5(t_stack **a, t_stack **b);


#endif