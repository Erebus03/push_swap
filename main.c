#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return 0;
	if (!validate_input(ac, av, &stack_a))
	{
		lstclear(&stack_a);
		return 1;
	}
	printf("sorted? = %d\n", stack_is_sorted(stack_a));
	// t_stack *tmp = stack_a;

	// int i = 1;

	// printf("stack_a before\n");
	// for  (; tmp != NULL; tmp = tmp->next)
	// 	printf("stack a -- node[%d]->nbr = %d\n", i++, tmp->nbr);
	// // /* push to stack_b */
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
	lstclear(&stack_a);
	lstclear(&stack_b);
	return 0;
}