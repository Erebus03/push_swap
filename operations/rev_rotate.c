/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <rajianwar421@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:18:49 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 00:18:49 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_stack **head, int is_rrr_call)
{
	t_stack	*last_node;

	last_node = lstlast(*head);
	if (!last_node)
		return ;
	(last_node->prev)->next = NULL;
	last_node->next = *head;
	(*head)->prev = last_node;
	last_node->prev = NULL;
	*head = last_node;
	if (!is_rrr_call)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **head, int is_rrr_call)
{
	t_stack	*last_node;

	last_node = lstlast(*head);
	(last_node->prev)->next = NULL;
	last_node->next = *head;
	(*head)->prev = last_node;
	last_node->prev = NULL;
	*head = last_node;
	if (!is_rrr_call)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (a)
		rra(a, 1);
	if (b)
		rra(b, 1);
	write(1, "rrr\n", 3);
}
