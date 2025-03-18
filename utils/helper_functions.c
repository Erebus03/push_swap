/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <rajianwar421@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:19:13 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 00:19:13 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	stack_is_sorted(t_stack *stack)
{
	int (i), (size);
	i = 0;
	size = lstsize(stack);
	while (i++ < size - 1)
	{
		if (stack->nbr > (stack->next)->nbr)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

int	get_range(int size)
{
	if (size <= 100)
		return (size / 7);
	else if (size <= 500)
		return (size / 13);
	else
		return (50);
}

int	find_max(t_stack *head)
{
	int	max;

	if (!head)
		return (0);
	max = head->nbr;
	while (head->next != NULL)
	{
		if (max < (head->next)->nbr)
			max = (head->next)->nbr;
		head = head->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *head)
{
	t_stack	*min;

	min = head;
	while (head->next != NULL)
	{
		if (min->nbr > (head->next)->nbr)
			min = head->next;
		head = head->next;
	}
	return (min);
}

int	lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
