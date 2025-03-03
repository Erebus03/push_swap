#include "utils.h"

int	stack_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nbr > (stack->next)->nbr)
			return 0;
		else
			stack = stack->next;
	}
	return 1;
}
