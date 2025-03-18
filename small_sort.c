/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <rajianwar421@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:21:38 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 00:21:38 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_stack	*min;

	while (lstsize(*a) > 3)
	{
		min = find_min(*a);
		while (*a != min && (*a)->next == min)
			ra(a, 0);
		while (*a != min)
			rra(a, 0);
		pb(a, b);
	}
	sort3(a);
	pa(a, b);
	pa(a, b);
}
