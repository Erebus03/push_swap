#include "operations.h"

void	rra(t_stack **head, int is_rrr_call)
{
	t_stack	*last_node;

	last_node = lstlast(*head);
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
	(last_node->prev)->next = NULL;			//	last node to point to null
	last_node->next = *head;				//	make the lastnode first
	(*head)->prev = last_node;  			//	Make former head's prev point to the new head
	last_node->prev = NULL;					//	null before *head(lastnode)
	*head = last_node;						//	update the *head pointer
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