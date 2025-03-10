#include "push_swap.h"

void	sort3(t_stack **head)
{
	t_stack	*max;

	max = find_max(*head);
	if (*head == max)
		ra(head, 0);
	else if ((*head)->next == max)
		rra(head, 0);
	if (!stack_is_sorted(*head))
		sa(head, 0);
}

void	sort5(t_stack **a, t_stack **b)
{
	/* find the 2 min nbrs and push them to stack_b*/	
}