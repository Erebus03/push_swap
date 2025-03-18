/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <rajianwar421@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:18:52 by araji             #+#    #+#             */
/*   Updated: 2025/03/18 00:18:52 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack **head, int is_rr_call)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if(!*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	if(!*head)
		return ;
	(*head)->prev = NULL;
	last_node = lstlast(*head);
	last_node->next = tmp;
	tmp->prev = last_node;
	tmp->next = NULL;
	if (!is_rr_call)
		write(1, "ra\n", 3);
}
void	rb(t_stack **head, int is_rr_call)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if(!*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	if(!*head)
		return ;
	(*head)->prev = NULL;
	last_node = lstlast(*head);
	last_node->next = tmp;
	tmp->prev = last_node;
	tmp->next = NULL;
	if (!is_rr_call)
		write(1, "rb\n", 3);
}
void	rr(t_stack **a, t_stack **b)
{
	if (a)
		ra(a, 1);
	if (b)
		ra(b, 1);
	write(1, "rr\n", 3);
}
