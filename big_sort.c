#include "push_swap.h"

void	printf_stacks(t_stack **a, t_stack **b)
{
	t_stack *tmp = *a;
	int i = 1;
	printf("stack_a\n");
	for  (; tmp != NULL; tmp = tmp->next)
		printf("stack a in bs -- node[%d]->nbr = %d\n", i++, tmp->nbr);
	t_stack *ss = *b;
	i = 1;
	printf("stack_b\n");
	for  (; ss != NULL; ss = ss->next)
		printf("stack b in bs -- node[%d]->nbr = %d\n", i++, ss->nbr);
}

void	updateindex(int *i, int *j)
{
	*i += 1;
	*j += 1;
}

void	bigsort(t_stack **a, t_stack **b, int *arr, int n)
{
	int (i), (j);
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		if ((*a)->nbr <= arr[i])
		{
			pb(a, b);
			updateindex(&i, &j);
			if ((*a)->next != NULL)
				rb(b, 0);
		}
		else if ((*a)->nbr <= arr[j])
		{
			pb(a, b);
			updateindex(&i, &j);
			if ((*b)->next)
				if ((*b)->nbr <= ((*b)->next)->nbr)
					sb(b, 0);
		}
		else
			ra(a, 0);
		printf_stacks(a, b);
	}


	// swapback(a, b);
}
