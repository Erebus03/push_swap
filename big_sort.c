#include "push_swap.h"

int	max_in_first_half(t_stack **stack, int size, int max)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = -1;
	// printf("max = %d\nsize = %d\nstack = %p\n", max, size, tmp);
	while (++i < (size / 2))
	{
		// printf("%d vs %d\n", tmp->nbr, max);
		if (tmp->nbr == max)
			return 1;
		tmp = tmp->next;
	}
	// write(1, "no segf here\n", 13);
	return 0;
}

void	updateindex(int *i, int *j, int size)
{
	*i += 1;
	if (*j < size)
		*j += 1;
}

void	swapback(t_stack **a, t_stack **b, int n)
{
	t_stack *max;
	max = (find_max(*b));
	// write(1, "swaping back\n", 13);
	// printf("max = %p, max.nbr = %d\n", max, max->nbr);
	// printf("b head  = %p\n", *b);
	if (max_in_first_half(b, n, max->nbr))
	{
		// write(1, "in FirstHalf\n", 13);
		while ((*b)->nbr != max->nbr)
			ra(a, 0);
		// write(1, "pushing toSA\n", 13);
		pa(a, b);
	}
	else
	{
		// write(1, "second  half\n", 13);
		while ((lstlast(*b))->nbr != max->nbr)
		{
			// printf("max = %p, max.nbr = %d\n*b = %p, *b.nbr = %d\n", max, max->nbr, *b, (*b)->nbr);
			rra(a, 0);
		}
		// write(1, "reverse rated\n", 14);
		
		pa(a, b);	
	}
}

void	bigsort(t_stack **a, t_stack **b, int *arr, int n)
{
	int (i), (j);
	i = 0;
	j = get_range(n);
	while (*a)
	{
		if ((*a)->nbr <= arr[i])
		{
			pb(a, b);
			updateindex(&i, &j, n);
			if ((*b)->next != NULL)
				rb(b, 0);
		}
		else if ((*a)->nbr <= arr[j])
		{
			pb(a, b);
			updateindex(&i, &j, n);
			if ((*b)->next)
				if ((*b)->nbr <= ((*b)->next)->nbr)
					sb(b, 0);
		}
		else
			ra(a, 0);
	}
	swapback(a, b, n);
}

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
