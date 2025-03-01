#include "push_swap.h"

void free_args(int ac, char **args) {
	int i;
	
	while (--ac)
		free (args[i++]);
	free(args);
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (ac < 2)
		return 0;
	validate_input(ac, av, &stack_a);
	
	return 0;
}