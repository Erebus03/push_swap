#include "push_swap.h"

void	cleanup(t_stack **a, t_stack **b, int *int_array)
{
	lstclear(a);
	lstclear(b);
	free(int_array);
}

void	selection_sort(int **array, int size)
{
	int *arr;

	int (i), (j), (min_index), (temp);
	arr = *array;
	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[min_index] > arr[j])
				min_index = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		i++;
	}
}

int	*generate_array(t_stack **head, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return NULL;
	tmp = *head;
	i = -1;
	while(++i < size)
	{
		array[i] = tmp->nbr;
		tmp = tmp->next;
	}
	if (array)
		selection_sort(&array, size);
	return array;
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int *ar;
	int size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return 0;
	if (!validate_input(ac, av, &stack_a))
	{
		lstclear(&stack_a);
		return 1;
	}
	if (stack_is_sorted(stack_a))
		return 0;

	size = lstsize(stack_a);
	ar = generate_array(&stack_a, size);

	// for (int i = 0; i < size; i++) {
	// 	printf("arr[%d] = %d\n", i, ar[i]);
	// }

	if (size <= 3)
		sort3(&stack_a);
	else if (size <= 5)
		sort5(&stack_a, &stack_b);

	else
		bigsort(&stack_a, &stack_b, ar, size);
	
	cleanup(&stack_a, &stack_a, ar);	
	return 0;
}
	
	
		// t_stack *tmp = stack_a;
		// int i = 1;
		// printf("stack_a\n");
		// for  (; tmp != NULL; tmp = tmp->next)
		// 	printf("stack a -- node[%d]->nbr = %d\n", i++, tmp->nbr);
	
		// tmp = stack_b;
		// i = 1;
		// printf("stack_b\n");
		// for  (; tmp != NULL; tmp = tmp->next)
		// 	printf("stack b -- node[%d]->nbr = %d\n", i++, tmp->nbr);
		

		
	// /* push to stack_b */
	// for (int i = 0; i < 10; i++) {
	// 	pb(&stack_a, &stack_b);
	// }

	// // rb(&stack_a, 0);
	// // rrb(&stack_b, 0);
	
	// tmp = stack_a;
	// i = 0;
	// printf("stack_a after\n");
	// for (; tmp != NULL; tmp = tmp->next)
	// 	printf("sstack a -- node[%d]->nbr = %d\n", i++, tmp->nbr);
	// tmp = stack_b;
	// printf("stack_b after\n");
	// for (; tmp != NULL ; tmp = tmp->next)
	// 	printf("stack b -- node[%d]->nbr = %d\n", i++, tmp->nbr);
	// for (int i = 0; i < 5; i++) {
	// 	rb(&stack_b, 0);
	// 	rrb(&stack_b, 0);
	// }
	// printf("stack b\n");
	// tmp = stack_b;
	// for (; tmp != NULL ; tmp = tmp->next)
	// 	printf("stack bb -- node[%d]->nbr = %d\n", i++, tmp->nbr);