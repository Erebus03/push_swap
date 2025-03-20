/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:20:58 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 01:27:36 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_stack **a, t_stack **b, int *int_array)
{
	lstclear(a);
	lstclear(b);
	free(int_array);
}

void	selection_sort(int **array, int size)
{
	int	*arr;

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
		return (NULL);
	tmp = *head;
	i = -1;
	while (++i < size)
	{
		array[i] = tmp->nbr;
		tmp = tmp->next;
	}
	if (array)
		selection_sort(&array, size);
	return (array);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*ar;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!validate_input(ac, av, &stack_a))
		return (lstclear(&stack_a), 1);
	size = lstsize(stack_a);
	if (stack_is_sorted(stack_a))
		return (cleanup(&stack_a, &stack_a, NULL), 0);
	ar = generate_array(&stack_a, size);
	if (size <= 3)
		sort3(&stack_a);
	else if (size <= 5)
		sort5(&stack_a, &stack_b);
	else
		bigsort(&stack_a, &stack_b, ar, size);
	return (cleanup(&stack_a, &stack_a, ar), 0);
}
