/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <rajianwar421@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:19:31 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 06:34:26 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_direction(t_stack **a, int *arr, int chunk_max)
{
	t_stack	*tmp;
	int		count_ra;
	int		count_rra;
	int		size;

	count_ra = 0;
	size = 0;
	size = lstsize(*a);
	tmp = *a;
	while (tmp && tmp->nbr > arr[chunk_max])
	{
		count_ra++;
		tmp = tmp->next;
	}
	count_rra = size - count_ra;
	if (count_ra <= count_rra)
		ra(a, 0);
	else
		rra(a, 0);
}

int	max_in_first_half(t_stack **stack, int size, int max)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = -1;
	while (++i < (size / 2))
	{
		if (tmp->nbr == max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	updateindex(int *i, int *j, int size)
{
	*i += 1;
	if (*j < size)
		*j += 1;
}

int 	find_max_pos(t_stack **stack, int max)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp && tmp->nbr != max)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	swapback(t_stack **a, t_stack **b, int n)
{
	int	(max), (size), (max_pos);
	size = n;
	while (*b != NULL)
	{
		size = lstsize(*b);
		max = find_max(*b);
		max_pos = find_max_pos(b, max);
		if (max_pos <= size / 2)
		{
			while ((*b)->nbr != max)
				rb(b, 0);
		}
		else
		{
			while (*b && ((*b)->nbr != max))
				rrb(b, 0);
		}
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
			rot_direction(a, arr, j);
	}
	swapback(a, b, n);
}
