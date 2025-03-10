#include "utils.h"

t_stack *find_max(t_stack *head)
{
	t_stack	*max;

	max = head;
	while (head->next != NULL)
	{
		if (max->nbr < (head->next)->nbr)
			max = head->next;
		head = head->next;
	}
	return max;
}

t_stack *find_min(t_stack *head)
{
	t_stack	*min;

	min = head;
	while (head->next != NULL)
	{
		if (min->nbr > (head->next)->nbr)
			min = head->next;
		head = head->next;
	}
	return min;
}
