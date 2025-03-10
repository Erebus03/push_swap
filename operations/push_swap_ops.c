#include "operations.h"

void	sa(t_stack **head, int is_ss_call)
{
	t_stack	*tmp;

	if (!*head || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	(*head)->prev = NULL;
	if (!is_ss_call)
		write(1, "sa\n", 3);
}
void	sb(t_stack **head, int is_ss_call)
{
	t_stack	*tmp;

	if (!*head || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	(*head)->prev = NULL;
	if (!is_ss_call)
		write(1, "sb\n", 3);
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		sa(stack_a, 1);
	if (stack_b)
		sb(stack_b, 1);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (!*b)
		return ;
	tmp = (*b);
	*b = (*b)->next;
	lstadd_front(a, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (!*a)
		return ;
	tmp = (*a);
	*a = (*a)->next;
	lstadd_front(b, tmp);
	write(1, "pb\n", 3);
}